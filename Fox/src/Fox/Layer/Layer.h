#pragma once

#include "Fox/Event/Event.h"

namespace Fox
{
    class Layer
    {
    public:
        virtual ~Layer() = default;

        virtual void OnAttach() = 0;
        virtual void OnDetach() = 0;
        virtual void OnUpdate(float timeStep) = 0;
        virtual void OnUIRender() = 0;
        virtual void OnEvent(Event& event) = 0;
    };
}
