#include "main.h"

nv_api::nv_api()
{
   if (NvAPI_Initialize() != NVAPI_OK)
      throw std::runtime_error("NVIDIA Api not initialized");

   if (NvAPI_DRS_CreateSession(&session_) != NVAPI_OK)
      throw std::runtime_error("can't create session");

   if (NvAPI_DRS_LoadSettings(session_) != NVAPI_OK)
      throw std::runtime_error("can't load system settings");

   if (NvAPI_DRS_GetCurrentGlobalProfile(session_, &profile_) != NVAPI_OK)
      throw std::runtime_error("can't get current global profile");

   prof_info_.version = NVDRS_PROFILE_VER;

   if (NvAPI_DRS_GetProfileInfo(session_, profile_, &prof_info_) != NVAPI_OK)
      throw std::runtime_error("can't get current global profile info");

   init_map();
}

nv_api::~nv_api()
{
   NvAPI_DRS_DestroySession(session_);
}

void nv_api::change_setting( Node const & setting )
{
   if (setting["name"].IsNull())
      return;

   string setting_name_str = setting["name"].as<string>();

   NvU32 setting_id = 0;

   wstring const w_setting_name_str(setting_name_str.begin(), setting_name_str.end());
   NvAPI_DRS_GetSettingIdFromName((NvU16 *)&w_setting_name_str[0], &setting_id);

   if (!setting_id)
   {
      cerr << "setting '" << setting_name_str << "' does not exist in driver" << endl;
      return;
   }

   string value_str;

   if (setting["value"].IsNull())
   {
      cout << "setting '" << setting_name_str << "' does not contain value" << endl;
      return;
   }

   value_str = setting["value"].as<string>();

   value_id_opt_t const setting_val = get_value_id_from_value_name(setting_id, value_str);

   if (!setting_val)
   {
      cout << "value of '" << setting_name_str << "' setting not support in this graphics driver manager version" << endl;
      return;
   }

   NVDRS_SETTING tmp_setting = {0};

   tmp_setting.version         = NVDRS_SETTING_VER;
   tmp_setting.settingId       = setting_id       ;
   tmp_setting.u32CurrentValue = *setting_val     ;
   tmp_setting.settingType     = NVDRS_DWORD_TYPE ;

   NvAPI_DRS_SetSetting(session_, profile_, &tmp_setting);
}

void nv_api::change_settings( Node const & settings )
{
   for (YAML::const_iterator it = settings.begin(); it != settings.end(); ++it)
      change_setting(*it);

   if (NvAPI_DRS_SaveSettings(session_) == NVAPI_OK)
      cout << "setting change successfully completed" << endl;
   else
      throw std::runtime_error("error save settings");
}

void nv_api::load_settings_from_file( string const & file_name )
{
   Node const config = LoadFile(file_name);

   change_settings(config);
}

void nv_api::save_settings_to_file( string const & file_name )
{
   ofstream f_out;

   f_out.exceptions(ifstream::failbit | ifstream::badbit);

   try
   {
      f_out.open(file_name.c_str());
   }
   catch (std::exception const & )
   {
      throw std::runtime_error("file i/o error");
   }

   settings_t stgs(prof_info_.numOfSettings);

   NvU32 numSetRead = prof_info_.numOfSettings;

   stgs[0].version = NVDRS_SETTING_VER;

   NvAPI_DRS_EnumSettings(session_, profile_, 0, &numSetRead, &(stgs[0]));

   Emitter out;

   out << YAML::Comment("NVIDIA Graphics Driver setting file") << YAML::Newline << YAML::Newline
       << YAML::Comment("Settings list:") << YAML::Newline;

   for (size_t i = 0, setting_idx = 1; i < prof_info_.numOfSettings; ++i)
   {
      string const setting_name = NvUS_to_string(stgs[i].settingName);

      if (setting_name == "")
         continue;

      out << YAML::Comment((format("%1%) %2%") % setting_idx++ % setting_name).str()) << YAML::Newline;
   }

   out << YAML::BeginSeq;

   for (size_t i = 0; i < prof_info_.numOfSettings; ++i)
   {
      if (!stgs[i].settingId)
         continue;

      string const setting_name = NvUS_to_string(stgs[i].settingName);

      if (setting_name == "")
         continue;

      value_name_opt_t value_name = get_value_name_from_value_id(stgs[i].settingId
                                                                 ,(unsigned int)stgs[i].u32CurrentValue);

      out << YAML::BeginMap << YAML::Newline;

      out << YAML::Key << "name"  << YAML::Value << setting_name
          << YAML::Key << "value";

      if (value_name)
         out << YAML::Value << *value_name;
      else
         cout << setting_name << "contain unexpected value" << endl;

      NvU32 id;
      wstring const w_str(setting_name.begin(), setting_name.end());
      NvAPI_DRS_GetSettingIdFromName((NvU16 *)(&w_str[0]), &id);

      ostringstream o_str;

      o_str << "optional_values: ";

      print_optional_values(dword_settings_map_.find((unsigned int)id), o_str);

      out << YAML::Newline << YAML::Comment(o_str.str())
          << YAML::EndMap << YAML::Newline;
   }

   out << YAML::EndSeq;

   f_out << out.c_str();

   f_out.close();
}

void nv_api::print_optional_values( dword_map_t::iterator const & it, std::ostream & o_stream )
{
   if (it == dword_settings_map_.end())
      return;

   setting_value_id_map_t::iterator tmp_it;

   Emitter out;

   out << YAML::Flow
       << YAML::BeginSeq;

   for (tmp_it = it->second.begin(); tmp_it != it->second.end(); ++tmp_it)
      out << tmp_it->left;

   out << YAML::EndSeq;

   o_stream << out.c_str();
}

void nv_api::print_optional_id( dword_map_t::iterator const & it, std::ostream & o_stream )
{
   if (it == dword_settings_map_.end())
      return;

   setting_value_id_map_t::iterator tmp_it;

   Emitter out;

   out << YAML::Flow
       << YAML::BeginSeq;

   for (tmp_it = it->second.begin(); tmp_it != it->second.end(); ++tmp_it)
      out << tmp_it->left;

   out << YAML::EndSeq;

   o_stream << out.c_str();
}
