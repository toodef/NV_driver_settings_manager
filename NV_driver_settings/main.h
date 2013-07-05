#pragma once

#pragma warning(disable : 4996)
#pragma warning(disable : 4146)
#pragma warning(disable : 4103)

#include <iostream>
#include <fstream>
#include <vector>

#include <nvapi.h>
#include <NvApiDriverSettings.h>
#pragma comment(lib, "nvapi.lib")

#include <boost/format.hpp>
#include <boost/bimap.hpp>
#include <boost/program_options.hpp>

#include <yaml.h>
#pragma comment(lib, "yaml.lib")

using namespace std;
using namespace boost;
using namespace YAML;

#include "nv_api.h"

__forceinline NvAPI_UnicodeString & string_to_NvUS( const string & str )
{
   size_t len = str.length();

   static NvAPI_UnicodeString us = {0};

   for (size_t i = 0; i < len + 1; ++i)
      us[i] = (NvU16)(str.c_str()[i]);

   return us;
}

__forceinline string NvUS_to_string( const NvU16 * str )
{
   string new_string;

   unsigned int i = 0;

   while (str[i])
      new_string += (char)str[i], i++;

   return new_string;
}

__forceinline string NvUS_to_string( const NvAPI_UnicodeString * str )
{
   string new_string;

   unsigned int i = 0;

   while (str[i])
      new_string += (char)str[i], i++;

   return new_string;
}
