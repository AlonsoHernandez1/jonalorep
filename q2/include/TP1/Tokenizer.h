#ifndef TOKENIZER
#define TOKENIZER

#include <ctype.h>
#include <string>
#include <algorithm>
#include "Token.h"
#include "StringUtils.h"

/**
 * @brief Tokenizes text.
 * 
 * Extracts tokens from a text string.
 */
class Tokenizer {

private:
  // text to tokenize
  std::string mTextToTokenize;
  // offset for the last found token's start
  int tokenStart;
  // offset for the last found token's end
  int tokenEnd;
  //number of tokens found since last valid token
  int tokensFound;
  //List of stop words to filter out
  std::vector<std::string> mStopwords;

  /**
   * @brief Finds a token on text
   * 
   * @return Token Token info found on text
   */
  Token findToken();

  /**
   * @brief Validates wheather a token is valid or not
   * 
   * @param token Token to validate
   * @return true if token is a valid extraction
   * @return false if token is invalid or present on stopwords list 
   */
  bool validateToken(Token token);
  
public:
  /**
   * @brief Construct a new Tokenizer object
   * 
   * @param pTextToTokenize Text to extract tokens from
   */
  Tokenizer(std::string pTextToTokenize);
  
  /**
   * @brief Construct a new Tokenizer object
   * 
   * @param pTextToTokenize Text to extract tokens from
   * @param pStopWords list of words that will be ignored during token extraction
   */
  Tokenizer(std::string pTextToTokenize, std::vector<std::string> pStopWords);
  
  /**
   * @brief Destroy the Tokenizer object
   */
  ~Tokenizer();

  /**
   * @brief Get the next Token on the text
   * 
   * @return Token token's data. If no more tokens are available on the text the Token data will have an empty string and -1 for all other values.
   */
  Token getNextToken();

  /**
   * @brief Get the numbers of Tokens Found since last valid token 
   * 
   * @return int number of tokens found since last valid token
   */
  int getTokensFound();

};

#endif
