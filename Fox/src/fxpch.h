#pragma once

#include "Fox/Core/PlatformDetection.h"

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#if defined(FX_PLATFORM_WINDOWS)
#   include <Windows.h>
#elif defined (FX_PLATFORM_LINUX)
#   include <signal.h>
#endif


#include "Fox/Core/Core.h"
#include "Fox/Core/Log.h"
