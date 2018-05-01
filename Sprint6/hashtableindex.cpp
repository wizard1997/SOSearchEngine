#include "hashtableindex.h"

HashTableIndex::HashTableIndex()
{

}

void HashTableIndex::addWord(std::string& str, unsigned long qID)
{
    table.insert(str);

}
