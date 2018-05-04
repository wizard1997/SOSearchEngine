#pragma once

#include "word.h"
#include <iostream>
#include <vector>
#include <list>
#include "avltreeindex.h"
#include "hashtableindex.h"

class IndexInterface
{



    public:

        IndexInterface();

        //add a ord into AVL tree or Hash Table
        virtual void addWord(Word&);

        //adds a question id to the word's vector if that question has that word
        virtual void addQuestionForWord(unsigned long);

        virtual std::list<unsigned long>& getQuestionsForWord();

        virtual bool alreadyIndexed(Word&);



};


