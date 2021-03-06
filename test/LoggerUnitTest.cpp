#include <chrono>
#include <fstream>
#include <iostream>
#include <mutex>
#include <sstream>
#include <string>
#include <thread>

#include "Logger.h"
#include "LoggerConfig.h"
#include "date.h"

/*
  Objectives:
      - Test concurrency scenarios, ensure no logs are intermixed
      - Test proper timestamping
      - What happens if object doesn't support operator<<?  What kind of error?  Hopefuly compile time error
      - I think that's it

      1. Test multiple types written in one line
 */

Logger::Log GLogObject("LoggerTest.log");

void WriteToLogger()
{
    GLogObject.Write(Logger::Level::WARNING,
                     "The quick brown ",
                     "fox jumps ",
                     "over the ",
                     "lazy ",
                     "dog.");

    GLogObject.Write(Logger::Level::ERROR,
                     "Because nighttime ",
                     "is the best time ",
                     "to fight crime.");

    return;
}

void TestMultipleTypes()
{
    GLogObject.Write(Logger::Level::DEBUG,
                     "String ",
                     123,
                     " and integer.");

    return;
}

int main()
{
    std::cout << "Testing Logger Version: " << LOGGER_VERSION_MAJOR << "."
              << LOGGER_VERSION_MINOR << std::endl;

    auto t1{std::thread(TestMultipleTypes)};
    auto t2{std::thread(WriteToLogger)};
    WriteToLogger();
    auto t3{std::thread(WriteToLogger)};
    WriteToLogger();
    auto t4{std::thread(WriteToLogger)};
    auto t5{std::thread(WriteToLogger)};

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    return 0;
}
