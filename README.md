## Observations

Calling subsequent constructors on std::ofstream with the same file name result in any existing files with the same name being overwritten.  This can be avoided by having timestamps associated with each log file.

## ToDo
  - [ ] Add msbuild to system PATH
    - C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\MSBuild\Current\Bin\amd64\msbuild.exe

## CMake Learnings
  - Whichever directory 'cmake' is called from is where the build files will be generated.
    - How do you specify where you want build files to go in CMakeLists.txt?  You don't.  CMake builds in whatever directory 'cmake' is called from

  - Top-level CMakeLists.txt can call sub-directory CMakeLists.txt by using `add_subdirectory()` command
    - In this project, we call the `add_subdirectory("./test")` to build the unit test executable

  - Use `target_include_directories` command to specify where the compiler should look for header files  to avoid doing things like: `#include "../inc/Logger.h"`
    - The equivalent command for the linker to look for libraries is `link_directories`

## C++ Learnings

### Windows vs Linux
In Linux, the constructor:
```
Logger::Log::Log(std::string file) : filename{ file }
{
    auto now = Logger::GetTime();
    auto fullName =  now + "_" + filename;
    logFile = std::ofstream(fullName, std::ios::out); // Opens the file to write to

    inStr = std::stringstream("", std::ios_base::ate | std::ios_base::out | std::ios_base::in);
}
```

Successfully opens and writes to the specified log file name.

In Windows, this project builds and runs, but nothing is written to a file within the project's directories.  When adding a test `std::ofstream` that is run as part of `main()` in LoggerUnitTest, a file is successfully written:
```
    std::ofstream ofs("test.txt", std::ios::out);
    ofs << "asd;lfkjalsdfj";
    ofs.close();
```

Files that are being created from the LogObject's constructor fail to create the file!

When hard coding a string in the Log constructor `logFile.open("whatever")`, the file opens successfully.

When using the class member variable `filename`, the file opens successfully as well.  There's something about the temporary variable `fullName` that is causing issues.

**SOLUTION**: The date/time format was using illegal characters for Windows file names per [Microsoft Docs](https://docs.microsoft.com/en-us/windows/win32/fileio/naming-a-file).  The colon `:` and forward slash `/` characters are reserved and attempting to open a file with those characters will fail.
  - Old date format: 2020/08/25_23:15:12.123
  - New date format: 2020.08.25-23.15.12.123

### Using Copy Constructor that's Implicitly Delted
```
C:\Projects\Logger\src\Logger.cpp(34,1): error C2280: 'Logger::Log::Log(const Logger::Log &)': attempting to reference a deleted function [C:\Projects\Logger\build\Logger.vcxproj]
```

The copy constructor is used here.
```
// using implicitly created copy constructor which was deleted
Logger::Log foo = Logger::Log::Log("sample.log");
```

https://en.cppreference.com/w/cpp/language/copy_constructor
  - Copy constructor is deleted implicitly because:
    - T has non-static data members that cannot be copied (have deleted, inaccessible, or ambiguous copy constructors)

http://www.cplusplus.com/reference/fstream/ofstream/ofstream/
  - std::ofstream deletes the copy constructor, therefore, my Log object implicitly deletes the copy constructor as well

`Logger::Log foo = Logger::Log::Log("sample.log")` semantically (before C++17) creates a temporary Logger::Log using the string, and then uses the copy constructor to initialise foo with that temporary - and even if the compiler elides the copy it is required to diagnose the semantic use of the copy constructor. From C++17, the temporary will be elided. Before C++17, the fix is to change the definition to Logger::Log foo ("sample.log")

**Takeaway**: Prefer uniform/aggregate initialization.
