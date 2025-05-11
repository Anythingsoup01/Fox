#include "fxpch.h"
#include "RendererAPI.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

#if !defined(FX_RENDERER_OPENGL) && !defined(FX_RENDERER_VULKAN)
#define FX_RENDERER_OPENGL
#endif

namespace Fox
{
#   ifdef FX_RENDERER_OPENGL
    RendererAPI::API RendererAPI::s_API = RendererAPI::API::OPENGL;
#   endif

    Scope<RendererAPI>RendererAPI::Create()
    {
        switch (s_API)
        {
            case RendererAPI::API::NONE:    FX_API_ASSERT(false, "NO GRAPHICS API DEFINED!"); return nullptr;
            case RendererAPI::API::OPENGL:  return CreateScope<OpenGLRendererAPI>();
            default: FX_API_ASSERT(false, "RENDERERAPI NOT SUPPORTED!") return nullptr;
        }
    }
}
