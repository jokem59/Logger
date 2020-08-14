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
 */

Logger::Log GLogObject("LoggerTest.log");

void WriteToLog(std::string

int main()
{

}
