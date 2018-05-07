/** Owner: Jake Watkins **/

#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <bits/stdc++.h>
#include <functional>
#include <unordered_set>


class Word
{
    private:

        std::string stringData;


    public:

        std::vector<std::pair<int, unsigned long>> questionData;

        //Constructors, destructor
        Word();
        Word(std::string& str);
        Word(const Word& wordIn);
        ~Word();

        unsigned long getIDNumber();

        void addQuestionData(int, unsigned long);
        std::string getWordStr() const;
        void setWordStr(const std::string& str);

        std::vector<std::pair<int, unsigned long>> getMostFrequent();
        std::vector<unsigned long> getQuestions();

        //To deal with query booleans
        Word queryOR(Word, Word);
        Word queryAND(Word, Word);
        Word queryNOT(Word, Word);


        //operators
        bool operator==(const Word& rhs) const;
        bool operator!=(const Word& rhs) const;
        Word& operator=(const Word& input);
        bool operator>(const Word& rhs) const;
        bool operator<(const Word& rhs) const;

        friend std::ostream& operator<< (std::ostream& out, const Word& wordOut) {

        //overload stream insertion operator

            out << wordOut.stringData;
            return out;

        }



};


