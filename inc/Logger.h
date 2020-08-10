#pragma once

namespace Logger
{
    enum class Level
    {
        DEBUG,
        INFO,
        WARNING,
        ERROR
    };

    std::string GetTime();

    class Log
    {
    private:
        std::string filename;
        std::ofstream logFile;
        std::recursive_mutex fileMutex;

    public:
        Log(std::string file);
        ~Log();

        template<typename T>
        void Write(Level lvl, T arg)
        {
            std::lock_guard<std::recursive_mutex> lock(fileMutex);
            logFile << std::noskipws << arg << '\n';
            return;
        }

        template<typename T, typename... Args>
        void Write(Level lvl, T firstArg, Args... args)
        {
            std::lock_guard<std::recursive_mutex> lock(fileMutex);
            logFile << std::noskipws << firstArg;
            Write(lvl, args...);
            return;
        }
    };
}
