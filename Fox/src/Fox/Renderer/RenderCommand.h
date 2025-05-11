#pragma once
#include "RendererAPI.h"

#include <glm/glm.hpp>

#include "Fox/Core/Core.h"

namespace Fox
{
    class RenderCommand
    {
    public:
        static inline void Clear(const glm::vec4& clearColor)
        {
            s_RendererAPI->Clear(clearColor);
        }

    private:
        static Scope<RendererAPI> s_RendererAPI;
    };
}
