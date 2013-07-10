#pragma once

#include "common/stl.h"
#include "common/boost.h"

#include <iostream>
#include <fstream>

#include <nvapi/nvapi.h>
#include <nvapi/NvApiDriverSettings.h>

#pragma comment(lib, "nvapi.lib")

#include <boost/bimap.hpp>
#include <boost/program_options.hpp>

#include <yaml_cpp/yaml.h>

#ifdef _DEBUG
#pragma comment(lib, "yamld.lib")
#else
#pragma comment(lib, "yaml.lib")
#endif

using namespace std;
using namespace boost;
using namespace YAML;

#include "nv_api.h"
