#pragma once

#include <iostream>
#include <vector>

class IndexInterface
{

    private:

        std::vector<unsigned long> questionsContainingWord;

    public:

        IndexInterface();

        void addWord();
        void addQuestionForWord(unsigned long);
        std::list<unsigned long>& getQuestionsForWord();

};

