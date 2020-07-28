## Observations

Calling subsequent constructors on std::ofstream with the same file name result in any existing files with the same name being overwritten.  This can be avoided by having timestamps associated with each log file.
