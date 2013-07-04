#include "main.h"

nv_api::nv_api() :
     session_  (0)
   , profile_  (0)
{
   if (NvAPI_Initialize() != NVAPI_OK)
      cout << "NVIDIA Api not initialized!" << endl;

   if (NvAPI_DRS_CreateSession(&session_) != NVAPI_OK)
      cout << "Can't create session!" << endl;

   if (NvAPI_DRS_LoadSettings(session_) != NVAPI_OK)
      cout << "Can't load system settings!" << endl;

   NvAPI_DRS_GetCurrentGlobalProfile(session_, &profile_);

   prof_info_.version = NVDRS_PROFILE_VER;

   NvAPI_DRS_GetProfileInfo(session_, profile_, &prof_info_);

   init_map();
}

nv_api::~nv_api()
{
   NvAPI_DRS_DestroySession(session_);
}

bool nv_api::change_setting( const Node & setting )
{
   string setting_name_str;

   setting["name"] >> setting_name_str;

   NvU32 setting_id = 0;

   NvAPI_DRS_GetSettingIdFromName(string_to_NvUS(setting_name_str), &setting_id);

   string value_str;

   setting["value"] >> value_str;

   size_t setting_val = get_value_id_from_value_name(setting_id, value_str);

   NVDRS_SETTING tmp_setting = {0};

   tmp_setting.version         = NVDRS_SETTING_VER;
   tmp_setting.settingId       = setting_id       ;
   tmp_setting.u32CurrentValue = setting_val      ;
   tmp_setting.settingType     = NVDRS_DWORD_TYPE ;

   NvAPI_DRS_SetSetting(session_, profile_, &tmp_setting);

   return 1;
}

bool nv_api::change_settings( Node const & settings )
{
   for (YAML::Iterator it = settings.begin(); it != settings.end(); ++it)
      change_setting(*it);

   NvAPI_DRS_SaveSettings(session_);

   return 0;
}

bool nv_api::display_prof_contents()
{
   wprintf(L"-----Profile Name: %s\n", prof_info_.profileName);
   cout << " Number of Settings associated with the Profile: " << prof_info_.numOfSettings << endl;
   cout << " Is Predefined: " << prof_info_.isPredefined << endl;

   NvAPI_Status status;

   string tmp_str;

   if (prof_info_.numOfSettings > 0)
   {
      NVDRS_SETTING * set_array = new NVDRS_SETTING[prof_info_.numOfSettings];
      NvU32 numSetRead = prof_info_.numOfSettings, i;

      set_array[0].version = NVDRS_SETTING_VER;
      status = NvAPI_DRS_EnumSettings(session_, profile_, 0, &numSetRead, set_array);

      if (status != NVAPI_OK)
      {
         NvAPI_ShortString szDesc = {0};
         NvAPI_GetErrorMessage(status, szDesc);
         cout << "NVAPI error: " << szDesc;

         return false;
      }

      for (i = 0; i < numSetRead; i++)
      {
         if (set_array[i].settingLocation != NVDRS_CURRENT_PROFILE_LOCATION)
         {
            // (6) The settings that are not from the Current Profile 
            // are inherited from the Base or Global profiles. Skip them.
            continue;
         }

         wprintf(L"  Setting Name: %s\n", set_array[i].settingName);
         cout << "  Setting ID: " << set_array[i].settingId << endl;
         cout << "  Predefined? : " << set_array[i].isCurrentPredefined << endl;

         switch (set_array[i].settingType)
         {
            // (7) a setting can be of different types and be using
            // different fields on the NVDRS_SETTING union
         case NVDRS_DWORD_TYPE:
            cout << "  Setting Value: " << set_array[i].u32CurrentValue << endl;
            break;

         case NVDRS_BINARY_TYPE:
            {
               unsigned int len;

               cout << "  Setting Binary (length = " << set_array[i].binaryCurrentValue.valueLength << ") :" << endl;

               for(len = 0; len < set_array[i].binaryCurrentValue.valueLength; len++)
                  cout << set_array[i].binaryCurrentValue.valueData[len] << endl;
            }
            break;

         case NVDRS_WSTRING_TYPE:
            cout << "  Setting Value: " << set_array[i].wszCurrentValue << endl;
            break;
         }

         cout << endl;
      }
   }

   wprintf(L"-----End of %s profile_.\n\n", prof_info_.profileName);

   return true;
}

void nv_api::load_settings_from_file( const string & file_name )
{
   ifstream f_in(file_name.c_str());
   Parser pars(f_in);

   Node doc;

   pars.GetNextDocument(doc);

   change_settings(doc);

   f_in.close();
}

void nv_api::save_settings_to_file( const string & file_name )
{
   ofstream f_out(file_name.c_str());

   settings_t stgs(prof_info_.numOfSettings);

   NvU32 numSetRead = prof_info_.numOfSettings;

   stgs[0].version = NVDRS_SETTING_VER;

   NvAPI_DRS_EnumSettings(session_, profile_, 0, &numSetRead, &(stgs[0]));

   f_out << "# --NVIDIA Graphics Driver setting file." << endl << endl;

   f_out << "# Settings list(" << prof_info_.numOfSettings << " ithems):" << endl;

   for (unsigned int i = 0; i < prof_info_.numOfSettings; ++i)
      f_out << "# --" << NvUS_to_string(stgs[i].settingName) << endl;

   f_out << endl;

   dword_map_t::iterator it = dwrd_setting_map_.begin();

   for (unsigned int i = 0; i < prof_info_.numOfSettings; ++i)
   {
      string str = NvUS_to_string(stgs[i].settingName);

      f_out << "-" << endl;
      f_out << "  name: " << str << endl;

      str  = get_value_name_from_value_id(stgs[i].settingId, (unsigned int)stgs[i].u32CurrentValue);

      f_out << "  value: " << str << endl;

      f_out << "  #val_options: ";

      print_optional_values(it, f_out);

      f_out << endl;

      it++;
   }

   f_out.close();
}

void nv_api::print_optional_values( const dword_map_t::iterator & it, std::ostream & o_stream )
{
   bimap<string, unsigned int>::iterator d_it;

   if (it != dwrd_setting_map_.end())
   {
      o_stream << "[";

      for (d_it = it->second.begin(); d_it != it->second.end(); ++d_it)
      {
         if ((++d_it) != it->second.end())
            o_stream << (--d_it)->left << ", ";
         else
            o_stream << (--d_it)->left << "]" << endl;
      }
   }
}

void nv_api::print_optional_id( const dword_map_t::iterator & it, std::ostream & o_stream )
{
   bimap<string, unsigned int>::iterator d_it;

   if (it != dwrd_setting_map_.end())
   {
      o_stream << "[";

      for (d_it = it->second.begin(); d_it != it->second.end(); ++d_it)
      {
         if ((++d_it) != it->second.end())
            o_stream << (--d_it)->right << ", ";
         else
            o_stream << (--d_it)->right << "]" << endl;
      }
   }
}
