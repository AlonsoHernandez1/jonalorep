#include "StringUtils.h"

std::wstring stringUtils::convertToWide(std::string string) {
  return std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(string);
}

std::string stringUtils::convertToSimple(std::wstring wideString) {
  return std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(wideString);
}

std::string stringUtils::removeAccents(std::string str) {

  //List of characters with diacriticst to replace
  std::wstring diacriticCharacters = convertToWide("ŠŽšžŸ¥µÀÁÂÃÄÅÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖØÙÚÛÜÝßàáâãäåçèéêëìíîïðñòóôõöøùúûüýÿ");
  //List of replacement characters 
  std::vector<wchar_t> replacements = { 'S', 'Z', 's', 'z', 'Y', 'Y', 'u', 'A', 'A', 'A', 'A', 'A', 'A', 'C', 'E', 'E', 'E', 'E', 'I', 'I', 'I', 'I', 'D', 'N', 'O', 'O', 'O', 'O', 'O', 'O', 'U', 'U', 'U', 'U', 'Y', 's', 'a', 'a', 'a', 'a', 'a', 'a', 'c', 'e', 'e', 'e', 'e', 'i', 'i', 'i', 'i', 'o', 'n', 'o', 'o', 'o', 'o', 'o', 'o', 'u', 'u', 'u', 'u', 'y', 'y' };

  //Convert string to wstring 
  std::wstring wideString = std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(str);

  for (long unsigned int i = 0; i < wideString.length(); i++) {
    //get wide character at position i
    wchar_t c = wideString[i];
    //find if character in position i is in list of diacritic chars;
    int index = diacriticCharacters.find(c);
    if (index >= 0) {
      //it is. replace it by the replacement character
      wideString[i] = replacements.at(index);
    } else {
      //it's not. check if value is outside 1 byte range
      if( c > 127 ) {
        //it is. Replace it with a period.
        wideString[i] = '.';
      }
    }
  }

  //convert back to string and return
  return std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(wideString);
}


std::string stringUtils::toLower(std::string str) {
  std::string lowerCaseStr = str;
  for (long unsigned int i = 0; i < lowerCaseStr.length(); i++) {
    lowerCaseStr[i] = tolower(lowerCaseStr[i]);
  }
  return lowerCaseStr;
}

std::string stringUtils::removeTrailingEndline(std::string str) {  
  if(str.substr(str.length()-2, str.length()).compare("\r\n")==0) {
    return str.substr(0, str.length()-2);
  }
  if(str.substr(str.length()-1, str.length()).compare("\r")==0) {
    return str.substr(0, str.length()-1);
  }
  if(str.substr(str.length()-1, str.length()).compare("\n")==0) {
    return str.substr(0, str.length()-1);
  }
  return str;
}

