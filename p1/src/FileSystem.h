#include <dirent.h>
#include <sys/stat.h>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

#ifndef FILE_SYSTEM_FUNCTIONS
#define FILE_SYSTEM_FUNCTIONS

namespace CI0113 {

  std::vector<std::string> listContents(std::string path, bool folders, bool files);
  
  std::vector<std::string> listFolder(std::string path);

  std::vector<std::string> listFiles(std::string path);

}

#endif