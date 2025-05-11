#include "fxpch.h"
#include "GUI.h"

#include "Fox/Renderer/RendererAPI.h"
#include "Platform/OpenGL/ImGui/OpenGLGUI.h"

namespace Fox
{
    Scope<GUI> GUI::Create()
    {
        switch (RendererAPI::GetAPI())
        {
            case RendererAPI::API::NONE: FX_API_ASSERT(false, "NO RENDER API SET!"); return nullptr;
            case RendererAPI::API::OPENGL: return CreateScope<OpenGLGUI>();
            default: FX_API_ASSERT(false, "RENDER API NOT SUPPORTED!") return nullptr;
        }
    }
}
