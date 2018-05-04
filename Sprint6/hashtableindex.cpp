#include "hashtableindex.h"



HashTableIndex::HashTableIndex()
{

}


void HashTableIndex::addWord(Word& word)
{
    table.insert(word);
}

Word &HashTableIndex::getWord(Word& word)
{
    return table.getWord(word);
}

