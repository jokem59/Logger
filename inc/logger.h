#pragma once

namespace Logger
{
    class Log
    {
    private:
        std::string filename;
        std::ofstream logFile;

    public:
        enum class Level
        {
            DEBUG,
            INFO,
            WARNING,
            ERROR
        };

        Log(std::string file);
        ~Log();

        template<typename T>
        void Write(Level lvl, T arg)
        {
            logFile << arg;
            return;
        }

        template<typename T, typename... Args>
        void Write(Level lvl, T firstArg, Args... args)
        {
            logFile << firstArg;
            Write(lvl, args...);
            return;
        }
    };
}
