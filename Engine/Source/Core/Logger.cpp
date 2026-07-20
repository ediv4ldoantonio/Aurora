#include <Aurora/Core/Logger.h>

#include <iostream>
#include <sstream>

namespace Aurora
{
    LogLevel Logger::s_Level = LogLevel::Info;
    bool Logger::s_Initialized = false;

    void Logger::Initialize()
    {
        if (s_Initialized)
            return;

        s_Initialized = true;
        std::cout << "[Aurora] Logger initialized" << std::endl;
    }

    void Logger::Shutdown()
    {
        if (!s_Initialized)
            return;

        s_Initialized = false;
        std::cout << "[Aurora] Logger shutdown" << std::endl;
    }

    void Logger::SetLevel(LogLevel level)
    {
        s_Level = level;
    }

    void Logger::Write(LogLevel level, const std::string &message)
    {
        if (!s_Initialized)
            Initialize();

        if (static_cast<int>(level) < static_cast<int>(s_Level))
            return;

        const char *levelName = "INFO";
        switch (level)
        {
        case LogLevel::Trace:
            levelName = "TRACE";
            break;
        case LogLevel::Info:
            levelName = "INFO";
            break;
        case LogLevel::Warn:
            levelName = "WARN";
            break;
        case LogLevel::Error:
            levelName = "ERROR";
            break;
        case LogLevel::Critical:
            levelName = "CRITICAL";
            break;
        }

        std::cout << "[Aurora][" << levelName << "] " << message << std::endl;
    }
}
