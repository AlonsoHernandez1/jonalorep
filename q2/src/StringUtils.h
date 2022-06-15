/** @file StringUtils.h
 *  @brief Some common utilities for strings
 * 
 * Defines a few common utility functions useful when working with strings.
 * 
 * */ 


#ifndef STRING_UTILS
#define STRING_UTILS

#include <string>
#include <locale>
#include <codecvt>
#include <vector>

namespace stringUtils {

/**
  * Converts a string to a wstring
  * @param string string to convert
  * @return wstring with the string's content
  */
std::wstring convertToWide(std::string string);

/**
  * Converts a wstring to a string
  * @param wideString wstring to convert
  * @return string with the wstring's content
  */
std::string convertToSimple(std::wstring wideString);

/**
  * Takes a string and replaces all characters with diacritics with the most similar ASCII character.  
  * Removes any other character that cannot be replaced with a perido (.). 
  * For example:
  *   á -> a \n 
  *   ñ -> n\n 
  *   Ÿ -> Y\n 
  *   @ -> .\n 
  * @param str a constant character pointer.
  * @return string without accented characters
  */
std::string removeAccents(std::string str);

/**
  * Converts each character to it's lower case version if exists.
  * @param str string values
  * @return string with all lower case characters.
  */
std::string toLower(std::string str);


std::string removeTrailingEndline(std::string str);

}

#endif