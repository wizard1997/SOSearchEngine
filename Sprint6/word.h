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



    public:

        Word();
        Word(unsigned long num, std::string& str);
        ~Word();

        void addQuestionID(unsigned long num);
        std::vector<unsigned long> getQuestions() const;
        void setWordStr(const std::string& str);
        std::string getWordStr() const;

        //operators
        bool operator==(const Word& rhs) const;
        bool operator!=(const Word& rhs) const;
        Word& operator=(const Word& input);
        friend std::ostream& operator<< (std::ostream& out, const Word& wordOut) {

        //overload stream insertion operator

            out << wordOut.stringData;
            return out;

        }


};


