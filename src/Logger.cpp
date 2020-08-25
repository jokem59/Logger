#include <fstream>
#include <iostream>
#include <mutex>
#include <sstream>
#include <string>
#include <thread>
#include <unordered_map>

#include "Logger.h"
#include "LoggerConfig.h"
#include "date.h"

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

std::string
Logger::Log::LevelToString(Level lvl)
{
    switch(lvl)
    {
    case Logger::Level::DEBUG:
        return "DEBUG";
    case Logger::Level::INFO:
        return "INFO";
    case Logger::Level::WARNING:
        return "WARNING";
    case Logger::Level::ERROR:
        return "ERROR";
    default:
        return "UNDEFINED";
    }
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
