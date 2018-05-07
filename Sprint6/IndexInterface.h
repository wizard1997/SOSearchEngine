#pragma once

#include "Word.h"
#include <iostream>
#include <vector>
#include <list>

class IndexInterface
{


    public:

        //IndexInterface() {std::cout << "base constructor" << std::endl;}
        virtual void addWord(std::string, unsigned long) = 0;
        virtual void print() = 0;

        //returns a Word
        virtual Word& getWord(const Word&) = 0;

        virtual std::vector<unsigned long> mostFrequentOccurance(Word&) = 0;
        virtual void saveIndex(std::ofstream&) = 0;






        virtual ~IndexInterface() {

            std::cout << "base destructor" << std::endl;

        }

};



