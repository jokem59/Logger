## Observations

Calling subsequent constructors on std::ofstream with the same file name result in any existing files with the same name being overwritten.  This can be avoided by having timestamps associated with each log file.

## ToDo
  - [ ] Add msbuild to system PATH
    - C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\MSBuild\Current\Bin\amd64\msbuild.exe

## CMake Learnings
  - Whichever directory 'cmake' is called from is where the build files will be generated.
    - [X] How do you specify where you want build files to go in CMakeLists.txt?
      - You don't, cmake builds in whatever directory 'cmake' is called from

## C++ Learnings

- Implicitly using Copy Constructor
  - C:\Projects\Logger\src\Logger.cpp(34,1): error C2280: 'Logger::Log::Log(const Logger::Log &)': attempting to reference a deleted function [C:\Projects\Logger\build\Logger.vcxproj]

https://stackoverflow.com/questions/31264984/c-compiler-error-c2280-attempting-to-reference-a-deleted-function-in-visual

```
// using implicitly created copy constructor which was deleted
Logger::Log foo = Logger::Log::Log("sample.log");
```
 If the class definition declares a move constructor or move assignment operator, the implicitly declared copy constructor is defined as deleted
   - Where is the move constructor or move assignment operator defined?
