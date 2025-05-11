project "Fox"
    language "C++"
    dialect "17"
    kind "StaticLib"

    pch "src/fxpch.h"

    files
    {
        "src/*.cpp",
        "src/*.h",
    }

    includedirs
    {
        "src",
        "$(WORKSPACEDIR)/vendor/glfw/include",
        "$(WORKSPACEDIR)/vendor/glad/include",
        "$(WORKSPACEDIR)/vendor/spdlog/include",
        "$(WORKSPACEDIR)/vendor/glm",
        "$(WORKSPACEDIR)/vendor/imgui",
        "$(WORKSPACEDIR)/vendor/stb",
    }

    links
    {
        "glfw",
        "Glad",
        "GL",
        "ImGui",
        "stb"
    }

    defines
    {
        "FE_RENDERER_OPENGL",
        "GLFW_INCLUDE_NONE"
    }

    filter "configurations:Debug"
        defines "FX_DEBUG"

    filter "configurations:Release"
        defines "FX_RELEASE"

