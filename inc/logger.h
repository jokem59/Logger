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

    class Log
    {
    private:
        std::string filename;
        std::ofstream logFile;

        std::mutex fileMutex;

    public:
        Log(std::string file);
        ~Log();

        template<typename T>
        void Write(Level lvl, T arg)
        {
            //const std::lock_guard<std::mutex> lock(fileMutex);
            logFile << std::noskipws << arg << '\n';
            return;
        }

        template<typename T, typename... Args>
        void Write(Level lvl, T firstArg, Args... args)
        {
            //const std::lock_guard<std::mutex> lock(fileMutex);
            logFile << std::noskipws << firstArg;
            Write(lvl, args...);
            return;
        }
    };
}
