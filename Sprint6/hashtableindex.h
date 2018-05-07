#pragma once

#include "hashtable.h"
#include "indexinterface.h"
#include "word.h"



class HashTableIndex: public IndexInterface
{

    private:

        HashTable<Word> table;

    public:

        HashTableIndex() {std::cout << "hashtable construct" << std::endl;}
        void addWord(std::string, unsigned long);

        std::vector<unsigned long> mostFrequentOccurance(Word&);
        std::vector<unsigned long> getQuestionsForWord(Word&);
        Word& getWord(const Word&);
        void saveIndex(std::ofstream&);

        void print();

};


