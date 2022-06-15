#include <FileSystem.h>

using namespace std;

/*----------------------------------------
Para usar en sus proyectos deben crear un .h
donde se definan la funciones. 
En sus clases pueden importar ese .h
----------------------------------------*/

string checkEndSlash(string str){
  if(str.compare(str.length()-1, str.length(), "/") != 0) {
    return str + "/";
  } else {  
    return str;
  }
}

vector<string> CI0113::listContents(string path, bool folders, bool files) {

  vector<string> contents;

  string fullPath = checkEndSlash(path);

  char cPath[fullPath.length()];
  strcpy(cPath, fullPath.c_str());

  struct dirent* entry = nullptr;  
  DIR* dir = nullptr;

  dir = opendir(cPath);
  if (dir != nullptr) {
    while(( entry = readdir(dir) )) {
      if(entry->d_name[0] != '.') {
        
        //Build full path for file 
        char fullName[sizeof(cPath) + sizeof(entry->d_name)];
        strcpy(fullName, cPath);
        strcat(fullName, entry->d_name);
       
        struct stat sb;
        stat(fullName, &sb);
                
        //Add file's full name to content vector
        if(S_ISDIR(sb.st_mode) && folders) {
          contents.push_back(fullName);
        }
        if(S_ISREG(sb.st_mode) && files) {
          contents.push_back(fullName);
        }
      }
    }
  }
  closedir(dir);

  return contents;
}

vector<string> CI0113::listFolder(string path) {
  return listContents(path, true, false);
}

vector<string> CI0113::listFiles(string path) {
  return listContents(path, false, true);
}

 