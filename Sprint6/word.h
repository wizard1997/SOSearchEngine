#pragma once

#include <iostream>

class Word
{
    private:

        unsigned long questionID;
        std::string stringData;

    public:

        Word();
        Word(unsigned long&, std::string& str);

        void setQuestionID(unsigned long& num);
        unsigned long& getQuestionID();
        void setWordStr(std::string& str);
        std::string& getWordStr();


};


