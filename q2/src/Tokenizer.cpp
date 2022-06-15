#include "TP1/Tokenizer.h"

using namespace std;
using namespace stringUtils;


Tokenizer::Tokenizer(std::string pTextToTokenize) {
  //remove diacritics and lowercase string before tokenizing
  mTextToTokenize = toLower(removeAccents(pTextToTokenize));

  tokenStart = 0;
  tokenEnd = 0;
  tokensFound= 0;
}


Tokenizer::Tokenizer(std::string pTextToTokenize, vector<string> pStopWords) {
  //remove diacritics and lowercase string before tokenizing
  mTextToTokenize = toLower(removeAccents(pTextToTokenize));
  
  mStopwords = pStopWords;
  tokenStart = 0;
  tokenEnd = 0;
  tokensFound= 0;
}


Tokenizer::~Tokenizer() {
  //Nothing to delete here
}

bool Tokenizer::validateToken(Token token) {
  
  //Check if there are no more tokens on the string.
  if(token.startOffset < 0) {
    return true; //this is not a token, but return true so the caller knows that there are no more tokens.
  }

  //Check if token has only 1 character
  if(token.endOffset - token.startOffset <= 1) {
    return false;
  }

  //if token is on stop word list
  if(find(mStopwords.begin(), mStopwords.end(), token.token) != mStopwords.end()) {
    return false;
  } 
  // we found a valid token. Reset the tokenFound counte
  tokensFound = 0;
  return true;
}


Token Tokenizer::getNextToken() {
  //Get a token
  Token token = findToken();
  //Keep looking for tokens until we find a valid one
  while(!validateToken(token)) {
    token = findToken();
  }
  //return valid token
  return token;  
}

Token Tokenizer::findToken() {
  //Create a token struct with no values.
  Token token;
  token.startOffset = -1;
  token.endOffset = -1;
  token.positionIncrement = -1;

  bool foundToken = false;

  //iterate through the string being tokenized. Starting right after where the last token ended
  for(long unsigned int i = tokenEnd; i < mTextToTokenize.size(); i++) {
    //is alphabetic character and we hadn't found a token
    //This means we found the start of a token.
    if(isalpha(mTextToTokenize[i]) && !foundToken) {          
      foundToken = true;
      tokenStart = i;
      token.startOffset = i;
    }
    //it's not alphabetic and we had previously found a token. 
    //This means we found the end of a token.
    if(!isalpha(mTextToTokenize[i]) && foundToken) {      
      tokenEnd = i;
      token.endOffset = i;
      token.positionIncrement = ++tokensFound;
      token.token = mTextToTokenize.substr(tokenStart, tokenEnd - tokenStart);
      break; 
    }
  }
  
  if(foundToken && token.endOffset <= 0) {
    //we reached the end of the line and didnot find the end of the token.
    tokenEnd = mTextToTokenize.size(); //the end of the line
    token.endOffset = mTextToTokenize.size(); //end of the line
    token.positionIncrement = ++tokensFound; 
    token.token = mTextToTokenize.substr(tokenStart, tokenEnd - tokenStart);
  }

  //return an emtpy token
  return token;
}

/**
 *  Returns the number of tokens found on the text. 
 */
int Tokenizer::getTokensFound() {
  return tokensFound;
}