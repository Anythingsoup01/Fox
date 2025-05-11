set(SRCS
    src/Fox/Core/PlatformDetection.cpp
    src/Fox/Core/Application.cpp
    src/Fox/Core/Log.cpp
    src/Fox/Layer/LayerStack.cpp
    src/Fox/ImGui/ImGuiBuild.cpp
    src/Fox/ImGui/GUI.cpp
    src/Fox/Renderer/GraphicsContext.cpp
    src/Fox/Renderer/RendererAPI.cpp
    src/Fox/Renderer/RenderCommand.cpp
    src/Fox/Window/Window.cpp
    src/Platform/OpenGL/ImGui/OpenGLGUI.cpp
    src/Platform/OpenGL/OpenGLGraphicsContext.cpp
    src/Platform/OpenGL/OpenGLRendererAPI.cpp
    src/Platform/GLFW/GLFWInput.cpp
    src/Platform/GLFW/GLFWWindow.cpp
    src/fxpch.h
    src/Fox.h
    src/Fox/Core/Log.h
    src/Fox/Core/Entrypoint.h
    src/Fox/Core/Application.h
    src/Fox/Core/PlatformDetection.h
    src/Fox/Core/Input.h
    src/Fox/Core/KeyCodes.h
    src/Fox/Core/Core.h
    src/Fox/Layer/LayerStack.h
    src/Fox/Layer/Layer.h
    src/Fox/ImGui/GUI.h
    src/Fox/Event/MouseEvent.h
    src/Fox/Event/Event.h
    src/Fox/Event/KeyEvent.h
    src/Fox/Event/ApplicationEvent.h
    src/Fox/Renderer/RenderCommand.h
    src/Fox/Renderer/GraphicsContext.h
    src/Fox/Renderer/RendererAPI.h
    src/Fox/Window/Window.h
    src/Platform/OpenGL/OpenGLRendererAPI.h
    src/Platform/OpenGL/ImGui/OpenGLGUI.h
    src/Platform/OpenGL/OpenGLGraphicsContext.h
    src/Platform/GLFW/GLFWWindow.h
)
add_library(Fox STATIC ${SRCS})
set_property(TARGET Fox PROPERTY CXX_STANDARD 17)

target_precompile_headers(Fox PUBLIC src/fxpch.h)
target_include_directories(Fox PRIVATE
    src
    ${CMAKE_SOURCE_DIR}/vendor/glfw/include
    ${CMAKE_SOURCE_DIR}/vendor/glad/include
    ${CMAKE_SOURCE_DIR}/vendor/spdlog/include
    ${CMAKE_SOURCE_DIR}/vendor/glm
    ${CMAKE_SOURCE_DIR}/vendor/imgui
    ${CMAKE_SOURCE_DIR}/vendor/stb
)

target_link_libraries(Fox
    glfw
    Glad
    GL
    ImGui
    stb
)

target_compile_definitions(Fox PUBLIC
    FE_RENDERER_OPENGL
    GLFW_INCLUDE_NONE
)

if(CMAKE_BUILD_TYPE STREQUAL Debug)
target_compile_definitions(Fox
PUBLIC
    FX_DEBUG
)
endif(CMAKE_BUILD_TYPE STREQUAL Debug)
if(CMAKE_BUILD_TYPE STREQUAL Release)
target_compile_definitions(Fox
PUBLIC
    FX_RELEASE
)
endif(CMAKE_BUILD_TYPE STREQUAL Release)
