#pragma once

#include <iostream>

class Word
{
    private:

        unsigned long questionID;
        std::string stringData;

    public:

        Word();

        void setQuestionID(unsigned long);
        unsigned long getQuestionID();
        void setWordStr(std::string);
        std::string getWordStr();


};


