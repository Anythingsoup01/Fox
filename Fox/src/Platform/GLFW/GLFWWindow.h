#pragma once

#include "Fox/Window/Window.h"
#include "Fox/Renderer/GraphicsContext.h"

#include <GLFW/glfw3.h>

namespace Fox
{
    class GLFWWindow : public Window
    {
    public:
        GLFWWindow(const WindowProps& props);
        virtual ~GLFWWindow();

        void OnUpdate() override;

        virtual unsigned int GetWidth() const override { return m_Data.Width; }
        virtual unsigned int GetHeight() const override { return m_Data.Height; }

        inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
        void SetVSync(bool enabled) override;
        bool IsVSync() const override;

        virtual void* GetNativeWindow() const override;

        virtual float GetTime() override { return (float)glfwGetTime(); }

    private:
        GLFWwindow* m_Window;
        Scope<GraphicsContext> m_Context;

        struct WindowData {
            std::string Title;
            unsigned int Width, Height;
            bool VSync;
            EventCallbackFn EventCallback;
        };

        WindowData m_Data;
    private:
        virtual void Init(const WindowProps& props);
        virtual void Shutdown();
    };

}
