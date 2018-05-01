#pragma once

#include <iostream>
#include <vector>
#include <list>

class Word
{
    private:

        std::vector<unsigned long> questionsContainingWord;
        std::string stringData;
        int questionId;

    public:

        Word();
        Word(unsigned long num, std::string& str);

        void addQuestionID(unsigned long num);
        std::vector<unsigned long> getQuestions();
        void setWordStr(std::string& str);
        std::string& getWordStr();

        Word& operator=(Word&);

};


