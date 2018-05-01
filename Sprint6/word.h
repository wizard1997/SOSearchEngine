#pragma once

#include <iostream>
#include <vector>
#include <list>

class Word
{
    private:

        std::vector<unsigned long> questionsContainingWord;
        std::string stringData;

        int totalFrequency;

        int questionId;


    public:

        Word();
        Word(unsigned long num, std::string& str);

        void addQuestionID(unsigned long num);
        std::vector<unsigned long> getQuestions() const;
        void setWordStr(const std::string& str);
        std::string getWordStr() const;

        bool operator==(const Word& rhs) const;

        friend std::ostream& operator<< (std::ostream& out, const Word& wordOut) {

        //overload stream insertion operator

            out << wordOut.stringData;
            return out;

        }

};


