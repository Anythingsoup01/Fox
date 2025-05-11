#pragma once


extern Fox::Application* Fox::CreateApplication(int argc, char** argv);
bool g_ApplicationRunning = true;

namespace Fox
{
    int Main(int argc, char** argv)
    {
        Fox::Log::Init();
        while (g_ApplicationRunning)
        {
            Fox::Application* app = Fox::CreateApplication(argc, argv);
            app->Run();
            delete app;
        }
        return 0;
    }
}

int main(int argc, char** argv)
{
    return Fox::Main(argc, argv);
}
