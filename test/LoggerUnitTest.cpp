#include <chrono>
#include <fstream>
#include <iostream>
#include <mutex>
#include <sstream>
#include <string>
#include <thread>

#include "../inc/Logger.h"
#include "../inc/LoggerConfig.h"
#include "../inc/date.h"

/*
  Objectives:
      - Test concurrency scenarios, ensure no logs are intermixed
      - Test proper timestamping
      - What happens if object doesn't support operator<<?  What kind of error?  Hopefuly compile time error
      - I think that's it
 */

Logger::Log GLogObject("LoggerTest.log");

int main()
{
    std::cout << "Testing Logger Version: " << LOGGER_VERSION_MAJOR << "."
              << LOGGER_VERSION_MINOR << std::endl;

    GLogObject.Write(Logger::Level::INFO,
                     "Testing ",
                     123,
                     " hahha");

    return 0;
}
