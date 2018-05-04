#pragma once

#include "word.h"
#include <iostream>
#include <vector>
#include <list>

class IndexInterface
{


    public:

        IndexInterface();

        //
        virtual void addWord(std::string, unsigned long) = 0;

        //returns a Word
        virtual Word& getWord(Word&) = 0;

        //adds a question id to the word's vector if that question has that word
        virtual void addQuestionForWord(unsigned long) = 0;

        virtual std::list<unsigned long>& getQuestionsForWord() = 0;

        virtual bool alreadyIndexed(Word&) = 0;



};

