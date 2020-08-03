#include <iostream>
#include <string>
#include <fstream>
#include "Logger.h"
#include "LoggerConfig.h"

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
    // report version
    std::cout << " Version " << LOGGER_VERSION_MAJOR << "."
              << LOGGER_VERSION_MINOR << std::endl;

    Logger::Log foo = Logger::Log::Log("sample.log");

    return 0;
}
