#pragma once

namespace Logger
{
    class Log
    {
    private:
        std::string filename;

    public:
        Log(std::string file) : filename{ file }
        {}
    }
}
