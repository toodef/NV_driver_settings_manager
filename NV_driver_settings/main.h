#pragma once

#include <iostream>
#include <fstream>

#include <nvapi.h>
#include <NvApiDriverSettings.h>
#pragma comment(lib, "nvapi.lib")

#include <boost/format.hpp>

#pragma warning(disable : 4996)
#pragma warning(disable : 4146)

#include <yaml.h>
#pragma comment(lib, "yaml.lib")

using namespace std;
using namespace boost;
using namespace YAML;

#include "nv_api.h"
