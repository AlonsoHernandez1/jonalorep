#ifndef DOCUMENT_REPOSITORY_PROC
#define DOCUMENT_REPOSITORY_PROC

#include <string>
#include <fstream>
#include "List.h"
#include "FileSystem.h"
#include "Tokenizer.h"
#include "StringUtils.h"
#include "BinaryFilesUtils.h"

const std::string textFileExtension = "txt";
const std::string binaryFileExtension = "dat";

/**
 * @brief Document Repository Processor
 * 
 * Crawls a document repository processing text documents
 * Each document found is analysed to extract valid tokens
 * A binary file with the extracted documents will be created.
 * 
 */
class DocumentRepositoryProcessor {

private:
  //Path to document repository
  std::string mDocumentRepositoryPath;
  //Path to stopwords file
  std::vector<std::string> stopWords;

  /**
   * @brief Processes a folder found during repository crawl.
   * 
   * @param folderPath path to folder to process
   */
  void processFolder(std::string folderPath);
  
  /**
   * @brief Processes a file found during repository crawl.
   * Ignores file that are not text files
   * 
   * Extracts a list of tokens from the file and creates 
   * a binary file containing the extracted tokens.
   * 
   * @param filePath path to file.
   */
  void processFile(std::string filePath);
  
  /**
   * @brief Checks if the name of a file ends in .txt.
   * 
   * @param filePath file path to validate
   * @return true if file's name ends in .txt
   * @return false otherwise
   */
  bool isTxtDocument(std::string filePath);

  /** 
   * @brief Generates the name for the binary file to write
   * 
   * New file's name is based on the original text file's name
   * 
   * @param filePath original file path for text file
   * @return std::string string with file path for binary file
   */
  std::string generateBinDocumentPath(std::string filePath);
  
  /**
   * @brief Processes a line of text extracted from a text file.
   * 
   * Uses the tokenizer to get a list of Tokens from the line. 
   * Adjusts the offsets and 
   * 
   * @param line line to analyse
   * @param lineOffset offset of the line inside the file
   * @param tokensFound number of token found on previus lines since the last valid token.
   * @param tokenList list of Tokens found on the file so far. 
   * @return int number of ignored tokens at end of line, if any. 
   */
  int processLine(std::string line, int lineOffset, int tokensFound, List<Token>* tokenList);
  
  /**
   * @brief Loads stopwords into an in-memory list.
   * 
   * @param filePath path to stopwords file.
   */
  void loadStopWords(std::string filePath);

public:
  /**
   * @brief Construct a new Document Repository Processor object
   * 
   * @param pDocumentRepositoryPath Path to document Repository
   * @param pStopWordsFilePath Path to stop words file
   */
  DocumentRepositoryProcessor(std::string pDocumentRepositoryPath, std::string pStopWordsFilePath);
  
  /**
   * @brief Destroy the Document Repository Processor object
   * 
   */
  ~DocumentRepositoryProcessor();

  /**
   * @brief Process the document repository
   */
  void process();

};

#endif