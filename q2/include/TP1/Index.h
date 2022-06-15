#ifndef INDEX
#define INDEX

#include <map>
#include <string>

using doc_id                = size_t;
using doc_path              = std::string;
using word                  = std::string;

struct word_info
{
  doc_id    document;
  double    tf;
};

extern std::map     <doc_id, doc_path>     doc_index;
extern std::multimap<word,   word_info>    word_index;

/**
 * ...
 * @param  datadile   Path to a datafile associated with a tyext file.
 *
 * @return The newly assigned ID for this docuemnt.
 */
doc_id add_document_to_index(std::string datafile);

// similarly, function to add word_info to oword index...
#endif
