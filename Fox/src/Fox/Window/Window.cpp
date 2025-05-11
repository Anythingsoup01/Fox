#include "fxpch.h"
#include "Window.h"

#include "Platform/GLFW/GLFWWindow.h"

namespace Fox
{
    Scope<Window> Window::Create(const WindowProps& props)
    {
        switch (PlatformDetection::GetPlatform())
        {
            case PlatformAPI::WINDOWS:
            case PlatformAPI::LINUX:
                return CreateScope<GLFWWindow>(props);

            default:
                FX_API_ASSERT(false, "Current platform not supported!");
                return nullptr;

        }
    }
}
