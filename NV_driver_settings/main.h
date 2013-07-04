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

#include <yaml.h>
#pragma comment(lib, "yaml.lib")

using namespace std;
using namespace boost;
using namespace YAML;

#include "nv_api.h"
