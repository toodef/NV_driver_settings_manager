#include "main.h"

nv_api::nv_api() :
     session_(0)
   , profile_(0)
{
   if (NvAPI_Initialize() != NVAPI_OK)
      cout << "NVIDIA Api not initialized!" << endl;

   if (NvAPI_DRS_CreateSession(&session_) != NVAPI_OK)
      cout << "Can't create session!" << endl;

   if (NvAPI_DRS_LoadSettings(session_) != NVAPI_OK)
      cout << "Can't load system settings!" << endl;

   NvAPI_DRS_GetCurrentGlobalProfile(session_, &profile_);

   init_map();
}

nv_api::~nv_api()
{
   NvAPI_DRS_DestroySession(session_);
}

// temp
NvAPI_UnicodeString & string_to_NvUS( const string & str )
{
   size_t len = str.length();

   static NvAPI_UnicodeString us = {0};

   for (size_t i = 0; i < len + 1; ++i)
      us[i] = (NvU16)(str.c_str()[i]);

   return us;
}

bool nv_api::change_setting( const Node & setting )
{
   string setting_name_str;

   setting["name"] >> setting_name_str;

   NvU32 setting_id = 0;

   NvAPI_DRS_GetSettingIdFromName(string_to_NvUS(setting_name_str), &setting_id);

   string value_str;

   setting["value"] >> value_str;

   size_t setting_val = get_value_id_from_setting_id(setting_id, value_str);

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
   NVDRS_PROFILE prof_info;

   prof_info.version = NVDRS_PROFILE_VER;

   NvAPI_DRS_GetProfileInfo(session_, profile_, &prof_info);

   const char * ch = (const char *)(&(prof_info.profileName[0]));

   wprintf(L"-----Profile Name: %s\n", prof_info.profileName);
   cout << " Number of Applications associated with the Profile: " << prof_info.numOfApps << endl;
   cout << " Number of Settings associated with the Profile: " << prof_info.numOfSettings << endl;
   cout << " Is Predefined: " << prof_info.isPredefined << endl;

   NvAPI_Status status;

   string tmp_str;

   if (prof_info.numOfApps > 0)
   {
      NVDRS_APPLICATION * app_array = new NVDRS_APPLICATION[prof_info.numOfApps];
      NvU32 numAppsRead = prof_info.numOfApps, i;

      app_array[0].version = NVDRS_APPLICATION_VER;
      status = NvAPI_DRS_EnumApplications(session_, profile_, 0, &numAppsRead, app_array);

      if (status != NVAPI_OK)
      {
         NvAPI_ShortString szDesc = {0};
         NvAPI_GetErrorMessage(status, szDesc);
         cout << " NVAPI error: " << szDesc;
         delete[] app_array;

         return false;
      }

      for(i = 0; i < numAppsRead; i++)
      {
         wprintf(L"  Executable: %s\n", app_array[i].appName);
         wprintf(L"  User Friendly Name: %s", app_array[i].userFriendlyName);
         cout << "  Is Predefined: " << app_array[i].isPredefined << endl;
      }

      delete[] app_array;
   }

   if (prof_info.numOfSettings > 0)
   {
      NVDRS_SETTING * set_array = new NVDRS_SETTING[prof_info.numOfSettings];
      NvU32 numSetRead = prof_info.numOfSettings, i;

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

   wprintf(L"-----End of %s profile_.\n\n", prof_info.profileName);

   return true;
}
