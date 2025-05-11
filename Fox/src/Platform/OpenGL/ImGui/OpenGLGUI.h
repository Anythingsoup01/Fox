#pragma once

#include "Fox/ImGui/GUI.h"

namespace Fox
{
    class OpenGLGUI : public GUI
    {
    public:
        virtual void Init() override;
        virtual void Shutdown() override;

        virtual void NewFrame() override;
        virtual void Render() override;
    };
}
