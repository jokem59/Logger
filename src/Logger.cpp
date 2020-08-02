#include <iostream>
#include <string>
#include <fstream>
#include "Logger.h"

Logger::Log::Log(std::string file) : filename{ file }
{
    logFile = std::ofstream(filename, std::ios::out);
    if (logFile.is_open())
    {
        logFile << "This is a log.\n";
    }
    else
    {
        std::cout << "Unable to open filename: " << filename << '\n';
    }

}

int main()
{
    Logger::Log foo = Logger::Log::Log("sample.log");

    return 0;
}
