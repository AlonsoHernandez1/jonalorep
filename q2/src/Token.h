
#ifndef TOKEN
#define TOKEN

#include <string>

/**
 * @brief Type for storing a token's data
 * 
 * Contains:
 *  - Token, the actual token extracted from text
 *  - positionIncrement, how many tokens were found since last valid token
 *  - startOffset position on file where token starts
 *  - endOffset position on file where token ends
 */
struct Token {
  std::string token; /**< Token extracted from file */
  int positionIncrement; /**< how many tokens were found since last valid token */
  int startOffset; /**< position on file where token starts */
  int endOffset; /**< position on file where token ends */
};

#endif