#pragma once

namespace Logger
{
    class Log
    {
    private:
        std::string filename;
        std::ofstream logFile;

    public:
        Log(std::string file);
    };
}
