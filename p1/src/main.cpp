#include <iostream>
#include <TP1/DocumentRepositoryProcessor.h>

using namespace std;
using namespace stringUtils;

//change this to your systems endline char
const string linebreak = "\n";


int main(int argc, char *argv[]) {
  
  string helpMessage = "Please provide one of this arguments: " + linebreak
    + "\th - display this help " + linebreak
    + "\t<directoryPath> - path to folder to work on" + linebreak
    + "\t<stopWordFilePath> - path to folder to work on" + linebreak;

  //Check that at least one command line argument was provided.
  if (argc < 2) {
    cout << helpMessage;
    return 0;
  }

  //convert argument to string
  string targetFolder(argv[1]);

  //check if argument is h and display help
  if(targetFolder.compare("h")==0) {
    cout << helpMessage;
    return 0;
  }
  
  //Check that at least one command line argument was provided.
  if (argc < 3) {
    cout << helpMessage;
    return 0;
  }
  
  string stopwordsFile(argv[2]);

  DocumentRepositoryProcessor docRepoProcessor(targetFolder , stopwordsFile);
  docRepoProcessor.process();

  return 0;
}