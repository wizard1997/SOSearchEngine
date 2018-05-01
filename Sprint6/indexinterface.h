#pragma once

#include <iostream>
#include <vector>

class IndexInterface
{



    public:

        IndexInterface();

        virtual void addWord(std::string&, unsigned long);
        virtual void addQuestionForWord(unsigned long);
        virtual std::list<unsigned long>& getQuestionsForWord();

        void getTaco();


};


