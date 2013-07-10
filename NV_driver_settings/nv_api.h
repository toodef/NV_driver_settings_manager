#pragma once

#include "boost/assign.hpp"

#include "main.h"

using boost::assign::map_list_of;
using boost::assign::list_of;

using namespace boost::bimaps;

class nv_api
{
public:
   nv_api ();
   ~nv_api();

   void display_prof_contents();

   void change_setting ( Node const & setting  );
   void change_settings( Node const & settings );

   void load_settings_from_file( string const & file_name );
   void save_settings_to_file  ( string const & file_name );

   static string NvUS_to_string( NvU16 const * str )
   {
      wstring const temp = wstring((wchar_t *)str);

      return string(temp.begin(), temp.end());
   }

   static string NvUS_to_string( NvAPI_UnicodeString const * str )
   {
      wstring const temp = wstring((wchar_t *)str);

      return string(temp.begin(), temp.end());
   }

private:
   void init_map();

   typedef bimap<string, unsigned int>        setting_value_id_map_t;
   typedef map<NvU32, setting_value_id_map_t> dword_map_t ;
   typedef setting_value_id_map_t::relation   rel_t;
   typedef vector<NVDRS_SETTING>              settings_t;

   typedef optional<size_t> value_id_opt_t  ;
   typedef optional<string> value_name_opt_t;

   void print_optional_values( dword_map_t::iterator const & it, std::ostream & o_stream );
   void print_optional_id    ( dword_map_t::iterator const & it, std::ostream & o_stream );

   value_id_opt_t get_value_id_from_value_name  ( NvU32 setting_id, string const & value_name );
   value_name_opt_t get_value_name_from_value_id( NvU32 setting_id, unsigned int value_id     );

   NvDRSSessionHandle session_  ;
   NvDRSProfileHandle profile_  ;
   NVDRS_PROFILE      prof_info_;

   dword_map_t dword_settings_map_;

};
