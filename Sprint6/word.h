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

        std::vector<std::pair<int, unsigned long>> questionData;
        std::string stringData;


    public:

        Word();
        Word(int frequency, unsigned long id, std::string& str);
        ~Word();


        void addQuestionData(int, unsigned long);
        std::string getWordStr() const;
        void setWordStr(const std::string& str);
        std::vector<std::pair<int, unsigned long>>& getQuestionData();

        std::vector<unsigned long> getMostFrequent(std::vector<std::pair<int, unsigned long>>& inputVectData);


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


