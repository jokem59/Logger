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

Logger::Log::~Log()
{
    // Wait and take write mutex

    // Close file
}

int main()
{
    // report version
    std::cout << " Version " << LOGGER_VERSION_MAJOR << "."
              << LOGGER_VERSION_MINOR << std::endl;

    Logger::Log foo{"sample.log"};

    foo.Write(Logger::Log::Level::INFO, "Testing", 123, "hahaha");

    return 0;
}
