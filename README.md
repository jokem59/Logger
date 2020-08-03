## Observations

Calling subsequent constructors on std::ofstream with the same file name result in any existing files with the same name being overwritten.  This can be avoided by having timestamps associated with each log file.

## ToDo
  - [ ] Add msbuild to system PATH
    - C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\MSBuild\Current\Bin\amd64\msbuild.exe

## CMake Learnings
  - Whichever directory 'cmake' is called from is where the build files will be generated.
    - [ ] How do you specify where you want build files to go in CMakeLists.txt?
  - Make OUTPUT of msbuild go to ./bin
