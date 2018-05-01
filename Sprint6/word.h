#pragma once

#include <iostream>
#include <vector>

class Word
{
    private:

        std::vector<unsigned long> questionsContainingWord;
        std::string stringData;

    public:

        Word();
        Word(unsigned long&, std::string& str);

        void setQuestionID(unsigned long& num);
        unsigned long& getQuestionID();
        void setWordStr(std::string& str);
        std::string& getWordStr();


};


