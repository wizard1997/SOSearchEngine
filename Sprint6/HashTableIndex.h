#pragma once

#include "HashTable.h"
#include "IndexInterface.h"
#include "Word.h"



class HashTableIndex: public IndexInterface
{

    private:

        HashTable<Word> table;

    public:

        HashTableIndex() {std::cout << "hashtable construct" << std::endl;}
        void addWord(std::string, unsigned long);

        Word& getWord(const Word&);
        void saveIndex(std::ofstream&);

        void print();

};


