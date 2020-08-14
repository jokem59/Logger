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
        std::stringstream inStr;
        std::ofstream logFile;
        std::recursive_mutex inStrMutex;
        std::mutex fileMutex;

        void ClearStrStream();

    public:
        Log(std::string file);
        ~Log();

        template<typename T>
        void Write(Level lvl, T arg)
        {
            std::lock_guard<std::recursive_mutex> inStrLock(inStrMutex);
            std::lock_guard<std::mutex> fileLock(fileMutex);
            inStr << std::noskipws << arg << '\n';
            logFile << std::noskipws << "[" << GetTime() << "] " << inStr.str();

            ClearStrStream();

            return;
        }

        template<typename T, typename... Args>
        void Write(Level lvl, T firstArg, Args... args)
        {
            std::lock_guard<std::recursive_mutex> lock(inStrMutex);
            inStr << std::noskipws << firstArg;
            Write(lvl, args...);
            return;
        }

    };
}
