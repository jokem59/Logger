#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include <mutex>
#include <sstream>
#include "Logger.h"
#include "LoggerConfig.h"
#include "date.h"

Logger::Log GFoo{"sample.log"};

Logger::Log::Log(std::string file) : filename{ file }
{
    auto now = Logger::GetTime();
    auto fullName =  now + "_" + filename;
    logFile = std::ofstream(fullName, std::ios::out);

    inStr = std::stringstream("", std::ios_base::ate | std::ios_base::out | std::ios_base::in);
}

Logger::Log::~Log()
{
    std::lock_guard<std::mutex> lock(fileMutex);

    logFile.close();
}

void
Logger::Log::ClearStrStream()
{
    inStr.str("");

    return;
}


std::string
Logger::GetTime()
{
    using namespace std::chrono;
    auto now = time_point_cast<milliseconds>(system_clock::now());
    return date::format("%F_%T", now);
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
