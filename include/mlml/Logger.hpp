#pragma once
#include <filesystem>
#include <stdlib.h>

namespace mlml
{
    enum class LogLevel
    {
        Debug,
        Info,
        Warning,
        Error
    };

    class Logger
    {
    private:
        Logger();
        ~Logger();

    public:
        static bool log(LogLevel level, std::wstring message);
    };
}
