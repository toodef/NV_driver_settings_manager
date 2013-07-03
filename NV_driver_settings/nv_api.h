#pragma once

#include "main.h"

class nv_api
{
public:
   nv_api();

   bool display_prof_contents();

   bool change_setting( Node const & setting );

   bool change_settings( Node const & settings );

private:
   unsigned int get_value_id_from_str( string const & setting_name, string const & value_name );

   NvDRSSessionHandle session_;
   NvDRSProfileHandle profile_;
};
