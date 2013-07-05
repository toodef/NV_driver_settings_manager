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

private:
   void init_map();

   typedef map<NvU32, bimap<string, unsigned int>> dword_map_t ;
   typedef map<NvU32, list<string>>                string_map_t;

   void print_optional_values( dword_map_t::iterator const & it, std::ostream & o_stream );
   void print_optional_id    ( dword_map_t::iterator const & it, std::ostream & o_stream );

   unsigned int nv_api::get_value_id_from_value_name( NvU32 setting_id, string const & value_name );
   string nv_api::get_value_name_from_value_id      ( NvU32 setting_id, unsigned int value_id )    ;

   NvDRSSessionHandle session_  ;
   NvDRSProfileHandle profile_  ;
   NVDRS_PROFILE      prof_info_;

   dword_map_t     dwrd_setting_map_;
   string_map_t    str_setting_map_ ;

   typedef bimap<string, unsigned int>::relation rel_t;

   typedef vector<NVDRS_SETTING> settings_t;
};
