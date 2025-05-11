#pragma once
#include <memory>

#if defined(FX_PLATFORM_LINUX)
#include <signal.h>
#include <stdio.h>
#   define FX_ASSERT(x) if (!(x)) { raise(SIGTRAP); }
#   define FX_API_ASSERT(x, ...) if (!(x)) { printf("%s\n", __VA_ARGS__); raise(SIGTRAP); }
#elif defined(FX_PLATFORM_WINDOWS)
#   define FX_ASSERT(x) if (!(x)) { __debugbreak(); }
#   define FX_API_ASSERT(x) if(!(x)) { Fox::Log::GetAPILogger()->critical(__VA_ARGS__); __debugbreak(); }
#endif

#define BIT(x) (1 << x)
#define BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Fox
{
    template<typename T>
    using Scope = std::unique_ptr<T>;
    template<typename T, typename ... Args>
    constexpr Scope<T> CreateScope(Args&& ... args)
    {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    template<typename T>
    using Ref = std::shared_ptr<T>;

    template<typename T, typename ... Args>
    constexpr Ref<T> CreateRef(Args&& ... args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }
}
