#pragma once
#include "Fox/Renderer/RendererAPI.h"

namespace Fox
{
    class OpenGLRendererAPI : public RendererAPI
    {
    public:
        virtual void Clear(const glm::vec4& clearColor);
    };
}
