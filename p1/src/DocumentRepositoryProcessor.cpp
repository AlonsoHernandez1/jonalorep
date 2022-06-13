#include "TP1/DocumentRepositoryProcessor.h"

using namespace std;
using namespace stringUtils;

DocumentRepositoryProcessor::DocumentRepositoryProcessor(string pDocumentRepositoryPath, string pStopWordsFilePath) {
  mDocumentRepositoryPath = pDocumentRepositoryPath;
  loadStopWords(pStopWordsFilePath);
}


DocumentRepositoryProcessor::~DocumentRepositoryProcessor() {
  //Nothing to delte here
}


bool DocumentRepositoryProcessor::isTxtDocument(std::string filePath) {  
  return filePath.substr(filePath.find_last_of('.')+1).compare(textFileExtension)==0;
}

string DocumentRepositoryProcessor::generateBinDocumentPath(std::string filePath) {  
  string binaryFilePath = filePath.substr(0, filePath.find_last_of('.')+1);
  binaryFilePath += binaryFileExtension;
  return binaryFilePath;
}



int DocumentRepositoryProcessor::processLine(string line, int lineOffset, int wordsFound, List<Token>* tokenList) {
  Tokenizer tokenizer(line, stopWords);
  Token token = tokenizer.getNextToken();
  //Add the number of ignored tokens from last line to this one.
  token.positionIncrement += wordsFound;
  while(token.endOffset != -1) {
    //Adjust token offsets. 
    //Tokenizer returns them from the start of the line. We need them from the start of the file.
    token.startOffset += lineOffset;
    token.endOffset += lineOffset;
    //Add token to list
    tokenList->add(token);
    //get another token
    token = tokenizer.getNextToken();
  }

  //return number of ignored tokens at end of line (since last not ignored token)
  return tokenizer.getTokensFound();
}

void DocumentRepositoryProcessor::processFile(string filePath) {
  
  //ignore documents that are not txt
  if(isTxtDocument(filePath)) {
    cout << "Processing file: " << filePath << endl;
    //Create a new list to store words
    List<Token>* wordList = new List<Token>();

    ifstream inputFile(filePath);
    if(inputFile.is_open()) {
      //if file was opened sucessfully
      string line;
      int fileLength = 0;
      int wordsFound = 0;
      //iterate through lines in file and process each
      while(getline(inputFile, line)) {
        //process line and save how many tokens were found and ignored after the last valid token
        wordsFound = processLine(line, fileLength, wordsFound, wordList);        
        //add length of line to length of file. Add extra 2 chars for linebreaks
        fileLength += line.size() + 2;
      }
      inputFile.close();
    } else {
      //if file was not opened
      //TODO: throw an exception
    }

    //We now have all the document tokens on the list.
    //Write the list to a binary file
    string binaryFilePath = generateBinDocumentPath(filePath);
    writeTokenListToFile(wordList, binaryFilePath);
    cout << "File " << filePath << " contained " << wordList->getSize() << " tokens." << endl;
    //Delete WordList
    delete wordList;
  } else {
    //Not a txt file.    
    cout << "Ignoring non txt file: " << filePath << endl;
  }
}


void DocumentRepositoryProcessor::loadStopWords(string filePath) {
  cout << "Loading stop words file: " << filePath << endl;
  stopWords.clear();
  ifstream inputFile(filePath);
  if(inputFile.is_open()) {
    //if file was opened sucessfully
    string line;
    //iterate through lines in file and process each
    while(getline(inputFile, line)){
      line = removeTrailingEndline(toLower(removeAccents(line)));
      stopWords.push_back(line);
    }
    inputFile.close();
  } else {
    //if file was not opened
    //TODO: throw an exception
  }
  cout << "Loaded " << stopWords.size() << " stop words from " << filePath << endl;
}

void DocumentRepositoryProcessor::processFolder(string folderPath) {
  cout << "Found folder: " << folderPath << endl;
  //Get a list of files inside this folder
  vector<string> files = CI0113::listFiles(folderPath);
  //Process each file
  for(string file : files) {    
    processFile(file);
  }

  //Get a list of folders inside this folder
  vector<string> folders = CI0113::listFolder(folderPath);  
  for(string folder : folders) {
    //Recursive call to process each folder found
    processFolder(folder);
  }
}



void DocumentRepositoryProcessor::process() {
  processFolder(mDocumentRepositoryPath);  
}