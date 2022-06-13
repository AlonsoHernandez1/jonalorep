/** @file BinaryFilesUtils.h
 *  @brief Some common utilities for reading and writing binary files
 * 
 * Defines a few common utility functions useful when working with binary files.
 * 
 * */ 

#ifndef BINARY_FILES_UTILS
#define BINARY_FILES_UTILS

#include "Token.h"
#include "List.h"
#include <fstream>
#include <string>

/**
 * @brief writes a Token list to a binary file  
 * 
 * Writes a new binary file with the contents of a token list.
 * 
 * @param list pointer to the list of tokens to write to file
 * @param fileName path to file.
 */  
void writeTokenListToFile(List<Token>* list, std::string fileName);

#endif