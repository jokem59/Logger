#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include <mutex>
#include "logger.h"
#include "LoggerConfig.h"

Logger::Log GFoo{"sample.log"};

Logger::Log::Log(std::string file) : filename{ file }
{
    logFile = std::ofstream(filename, std::ios::out);
}

Logger::Log::~Log()
{
    // Wait and take write mutex

    // Close file
    logFile.close();
}

void TestWrite()
{
    std::cout << "Calling TestWrite\n";
    GFoo.Write(Logger::Level::INFO,
               "One Two Three Four");
    GFoo.Write(Logger::Level::INFO,
               "Five Six Seven Eight");

    return;
}

int main()
{
    // report version
    std::cout << " Version " << LOGGER_VERSION_MAJOR << "."
              << LOGGER_VERSION_MINOR << std::endl;

    GFoo.Write(Logger::Level::INFO,
               "Testing ",
               123,
               " hahaha");

    std::thread t1(TestWrite);
    std::thread t2(TestWrite);

    t1.join();
    t2.join();

    return 0;
}
