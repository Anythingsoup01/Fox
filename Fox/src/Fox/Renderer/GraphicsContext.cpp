#include "fxpch.h"
#include "GraphicsContext.h"

#include "Fox/Renderer/RendererAPI.h"
#include "Platform/OpenGL/OpenGLGraphicsContext.h"

namespace Fox {

    Scope<GraphicsContext> GraphicsContext::Create(void* window)
    {

        switch (RendererAPI::GetAPI())
        {
            case RendererAPI::API::NONE:    FX_API_ASSERT(false, "NO GRAPHICS API DEFINED!"); return nullptr;
            case RendererAPI::API::OPENGL:  return CreateScope<OpenGLGraphicsContext>(static_cast<GLFWwindow*>(window));
            default: FX_API_ASSERT(false, "RENDERERAPI NOT SUPPORTED!") return nullptr;
        }

    }

}
