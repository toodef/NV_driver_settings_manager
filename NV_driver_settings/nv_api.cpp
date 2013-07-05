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

void nv_api::change_setting( Node const & setting )
{
   string setting_name_str;

   setting["name"] >> setting_name_str;

   NvU32 setting_id = 0;

   NvAPI_DRS_GetSettingIdFromName(string_to_NvUS(setting_name_str), &setting_id);

   string value_str;

   setting["value"] >> value_str;

   size_t const setting_val = get_value_id_from_value_name(setting_id, value_str);

   NVDRS_SETTING tmp_setting = {0};

   tmp_setting.version         = NVDRS_SETTING_VER;
   tmp_setting.settingId       = setting_id       ;
   tmp_setting.u32CurrentValue = setting_val      ;
   tmp_setting.settingType     = NVDRS_DWORD_TYPE ;

   NvAPI_DRS_SetSetting(session_, profile_, &tmp_setting);
}

void nv_api::change_settings( Node const & settings )
{
   for (YAML::Iterator it = settings.begin(); it != settings.end(); ++it)
      change_setting(*it);

   NvAPI_DRS_SaveSettings(session_);
}

void nv_api::display_prof_contents()
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

         return;
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
}

void nv_api::load_settings_from_file( string const & file_name )
{
   ifstream f_in;

   f_in.exceptions(ifstream::failbit | ifstream::badbit);

   try
   {
      f_in.open(file_name.c_str());
   }
   catch (ifstream::failure ex)
   {
      throw ex;
   }

   Parser pars(f_in);

   Node doc;

   pars.GetNextDocument(doc);

   change_settings(doc);

   f_in.close();
}

void nv_api::save_settings_to_file( string const & file_name )
{
   ofstream f_out;

   f_out.exceptions(ifstream::failbit | ifstream::badbit);

   try
   {
      f_out.open(file_name.c_str());
   }
   catch (ifstream::failure ex)
   {
      throw ex;
   }

   settings_t stgs(prof_info_.numOfSettings);

   NvU32 numSetRead = prof_info_.numOfSettings;

   stgs[0].version = NVDRS_SETTING_VER;

   NvAPI_DRS_EnumSettings(session_, profile_, 0, &numSetRead, &(stgs[0]));

   f_out << "# --NVIDIA Graphics Driver setting file." << endl << endl;

   f_out << "# Settings list:" << endl;

   string str;

   for (unsigned int i = 0; i < prof_info_.numOfSettings; ++i)
   {
      str = NvUS_to_string(stgs[i].settingName);

      if (str != "")
         f_out << "# " << i << ") " << str << endl;
   }

   f_out << endl;

   for (unsigned int i = 0; i < prof_info_.numOfSettings; ++i)
   {
      str = NvUS_to_string(stgs[i].settingName);

      if (str != "")
      {
         f_out << "-" << endl;
         f_out << "  name: " << str << endl;

         string d_str  = get_value_name_from_value_id(stgs[i].settingId, (unsigned int)stgs[i].u32CurrentValue);

         f_out << "  value: " << d_str << endl;

         f_out << "  #val_options: ";

         NvU32 id;

         NvAPI_DRS_GetSettingIdFromName(string_to_NvUS(str), &id);

         print_optional_values(dwrd_setting_map_.find((unsigned int)id), f_out);

         f_out << endl;
      }
   }

   f_out.close();
}

void nv_api::print_optional_values( dword_map_t::iterator const & it, std::ostream & o_stream )
{
   bimap<string, unsigned int>::iterator   d_it
                                         , prev_it;

   if (it != dwrd_setting_map_.end())
   {
      o_stream << "[";

      prev_it = it->second.end();

      --prev_it;

      for (d_it = it->second.begin(); d_it != it->second.end(); ++d_it)
      {
         if (d_it != prev_it)
            o_stream << d_it->left << ", ";
         else
            o_stream << d_it->left << "]" << endl;
      }
   }
}

void nv_api::print_optional_id( dword_map_t::iterator const & it, std::ostream & o_stream )
{
   bimap<string, unsigned int>::iterator   d_it
                                         , prev_it;

   if (it != dwrd_setting_map_.end())
   {
      o_stream << "[";

      prev_it = it->second.end();

      --prev_it;

      for (d_it = it->second.begin(); d_it != it->second.end(); ++d_it)
      {
         if (d_it != prev_it)
            o_stream << d_it->right << ", ";
         else
            o_stream << d_it->right << "]" << endl;
      }
   }
}
