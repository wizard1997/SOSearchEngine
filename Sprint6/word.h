#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <bits/stdc++.h>
#include <functional>

class Word
{
    private:

        std::string stringData;


    public:

        Word();
        Word(std::string& str);
        ~Word();

        std::map<int, unsigned long> questionData;

        void addQuestionData(int, unsigned long);
        std::string getWordStr() const;
        void setWordStr(const std::string& str);

      //  std::vector<unsigned long> getMostFrequent(std::map<int,unsigned long>& inputVectData);


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


        Word(const Word& wordIn);
};


