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

   bool display_prof_contents();

   bool change_setting ( Node const & setting );
   bool change_settings( Node const & settings );

   void load_settings_from_file( const string & file_name ); // from file do driver
   void save_settings_to_file  ( const string & file_name ); // from driver to file

private:
   void init_map();

   unsigned int get_value_id_from_setting_id( NvU32 id, std::string const & value_name );

   NvDRSSessionHandle session_  ;
   NvDRSProfileHandle profile_  ;
   NVDRS_PROFILE      prof_info_;


   typedef map<NvU32, bimap<string, unsigned int>> dword_map_t;
   typedef map<NvU32, list<string>>                string_map_t ;

   dword_map_t     dwrd_setting_map_;
   string_map_t    str_setting_map_ ;

   typedef vector<NVDRS_SETTING> settings_t;
};
