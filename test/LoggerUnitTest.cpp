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
      - I think that's it
 */

Logger::Log GLogObject("LoggerTest.log");



int main()
{

}
