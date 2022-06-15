#include "BinaryFilesUtils.h"

using namespace std;

/**
 * @brief writes a string to a binary file
 * 
 * Writes a string to a binary file:
 *  - 4 bytes. Int. lenght of string
 *  - N bytes. Multiple Characters. Content of string.
 * 
 * @param out output stream to write to. 
 * @param str string to write
 */
void writeStringToStream(ofstream& out, string str) {
  int strLen = str.size();
  out.write(reinterpret_cast<char const*>(&strLen), sizeof(strLen));
  out.write(str.c_str(), strLen);  
}

/**
 * Writes an integer value to a binary file
 * 
 * @param out output stream to write to. 
 * @param val int to write
 */
void writeIntegerToStream(ofstream& out, int val) {
  out.write(reinterpret_cast<char const*>(&(val)), sizeof(val)); 
}

/**
 * @brief Writes Token info to a binary file
 * 
 * Writes, in order:
 *  - String, token
 *  - int, position increment
 *  - int startOffset
 *  - int endOffset
 * @param out stream to write to
 * @param token Token to write
 */
void writeTokenToStream(ofstream& out, Token* token) {
  writeStringToStream(out, token->token);
  writeIntegerToStream(out, token->positionIncrement);
  writeIntegerToStream(out, token->startOffset);
  writeIntegerToStream(out, token->endOffset);  
}


void writeTokenListToFile(List<Token>* list, string fileName) {

  ofstream file(fileName, ios::binary);
  if(file.is_open()) {
    for(int i = 0; i < list->getSize(); i++){
      writeTokenToStream(file, list->getAt(i));
    }
    file.close();
  }
}
