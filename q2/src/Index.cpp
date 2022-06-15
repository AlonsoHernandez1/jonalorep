#include "TP1/Index.h"


std::map     <doc_id, doc_path>     doc_index;
std::multimap<word,   word_info>    word_index;



doc_id add_document_to_index(std::string path)
{
  auto id = doc_index.size();                   // assign path a new unique id

  doc_index.insert(std::make_pair(id, path));   // add id and path to index

  return id;
}
