#pragma once

#include "hashtable.h"
#include "indexinterface.h"



class HashTableIndex: public IndexInterface
{

    private:

        HashTable<Word> table;

    public:

        //HashTableIndex();
        void addWord(std::string, unsigned long);
        Word& getWord(Word&);



};


