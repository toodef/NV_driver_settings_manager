#pragma once

#include "boost/assign.hpp"

#include "main.h"

using boost::assign::map_list_of;
using boost::assign::list_of;

class nv_api
{
public:
   nv_api ();
   ~nv_api();

   void init_map();

   bool display_prof_contents();

   bool change_setting ( Node const & setting );
   bool change_settings( Node const & settings );

private:
   unsigned int get_value_id_from_setting_id( NvU32 id, string const & value_name );

   NvDRSSessionHandle session_;
   NvDRSProfileHandle profile_;

   typedef map<NvU32, map<string, unsigned int>> dword_map_t ;
   typedef map<NvU32, list<string>>              string_map_t;

   dword_map_t  dword_map ;
   string_map_t string_map;
};
