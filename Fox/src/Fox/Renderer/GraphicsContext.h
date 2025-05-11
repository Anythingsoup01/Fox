#pragma once
#include "Fox/Core/Core.h"

namespace Fox
{

    class GraphicsContext
    {
    public:
        virtual ~GraphicsContext() = default;
        virtual void Init() = 0;
        virtual void SwapBuffers() = 0;

        static Scope<GraphicsContext> Create(void* window);
    };
}
