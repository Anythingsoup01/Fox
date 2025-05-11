#include "fxpch.h"
#include "PlatformDetection.h"

namespace Fox
{
    PlatformAPI PlatformDetection::s_PlatformAPI;

    void PlatformDetection::Init()
    {
#       if defined(FX_PLATFORM_WINDOWS)
            s_PlatformAPI = PlatformAPI::WINDOWS;
#       elif defined(FX_PLATFORM_LINUX)
            s_PlatformAPI = PlatformAPI::LINUX;
#       else
            s_PlatformAPI = PlatformAPI::NONE;
#       endif

    }
}
