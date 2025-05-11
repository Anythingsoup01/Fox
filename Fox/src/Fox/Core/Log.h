#pragma once

#include "Core.h"
#include <spdlog/spdlog.h>

namespace Fox
{
    class Log
    {
    public:
        static void Init();

        static inline Ref<spdlog::logger>& GetAPILogger() { return s_APILogger; }
        static inline Ref<spdlog::logger>& GetCLILogger() { return s_CLILogger; }
    private:
        static Ref<spdlog::logger> s_APILogger;
        static Ref<spdlog::logger> s_CLILogger;
    };
}

#if defined(FX_DEBUG)
/*------ API RELATED LOG CALLS - TO BE USED ONLY IN FERRET! ------*/
#define FX_API_CRITICAL(...)  ::Fox::Log::GetAPILogger()->critical(__VA_ARGS__)
#define FX_API_ERROR(...)     ::Fox::Log::GetAPILogger()->error(__VA_ARGS__)
#define FX_API_WARN(...)      ::Fox::Log::GetAPILogger()->warn(__VA_ARGS__)
#define FX_API_INFO(...)      ::Fox::Log::GetAPILogger()->info(__VA_ARGS__)
#define FX_API_TRACE(...)     ::Fox::Log::GetAPILogger()->trace(__VA_ARGS__)

/*--- CLI RELATED LOG CALLS - TO BE USED IN FERRET BUILT APPS! ---*/
#define FX_CLI_CRITICAL(...)  ::Fox::Log::GetCLILogger()->critical(__VA_ARGS__)
#define FX_CLI_ERROR(...)     ::Fox::Log::GetCLILogger()->error(__VA_ARGS__)
#define FX_CLI_WARN(...)      ::Fox::Log::GetCLILogger()->warn(__VA_ARGS__)
#define FX_CLI_INFO(...)      ::Fox::Log::GetCLILogger()->info(__VA_ARGS__)
#define FX_CLI_TRACE(...)     ::Fox::Log::GetCLILogger()->trace(__VA_ARGS__)

#elif defined(FX_RELEASE)

/*------ API RELATED LOG CALLS - TO BE USED ONLY IN FERRET! ------*/
#define FX_API_CRITICAL(...)
#define FX_API_ERROR(...)
#define FX_API_WARN(...)
#define FX_API_INFO(...)
#define FX_API_TRACE(...)

/*--- CLI RELATED LOG CALLS - TO BE USED IN FERRET BUILT APPS! ---*/
#define FX_CLI_CRITICAL(...)  ::Fox::Log::GetCLILogger()->critical(__VA_ARGS__)
#define FX_CLI_ERROR(...)     ::Fox::Log::GetCLILogger()->error(__VA_ARGS__)
#define FX_CLI_WARN(...)      ::Fox::Log::GetCLILogger()->warn(__VA_ARGS__)
#define FX_CLI_INFO(...)      ::Fox::Log::GetCLILogger()->info(__VA_ARGS__)
#define FX_CLI_TRACE(...)     ::Fox::Log::GetCLILogger()->trace(__VA_ARGS__)
#endif
