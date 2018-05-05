#include "hashtableindex.h"



void HashTableIndex::addWord(std::string word, unsigned long idNum)
{

    Word &wordObj = table.insert(Word(word));

    if (wordObj.questionData.size() == 0) {

        wordObj.addQuestionData(1, idNum);
        return;

    }

    for (auto& w: wordObj.getQuestionData()) {

        if (w.second == idNum) {

            w.first++;
            return;

        }

    }

    wordObj.addQuestionData(1, idNum);
    std::cout  << wordObj.getQuestionDataSize() << std::endl;

    std::vector<std::pair<int, unsigned long>> vect = wordObj.getQuestionData();
    for (size_t i=0; i<vect.size(); i++)
    {

        std::cout << vect[i].first << " "
             << vect[i].second << std::endl;
    }

}

Word &HashTableIndex::getWord(Word& word)
{
    return table.getWord(word);
}



