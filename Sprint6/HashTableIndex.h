/** Owner: Jake Watkins **/

#pragma once

#include "HashTable.h"
#include "IndexInterface.h"
#include "Word.h"



class HashTableIndex: public IndexInterface
{

    private:

        HashTable<Word> table;

    public:

        HashTableIndex() {}
        void addWord(std::string, unsigned long);

        Word& getWord(const Word&);
        void saveIndex(std::ofstream&);
        void insert(Word &);
        void print();

};


