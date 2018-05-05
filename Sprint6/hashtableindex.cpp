#include "hashtableindex.h"



void HashTableIndex::addWord(std::string word, unsigned long idNum)
{
    Word &wordObj = table.insert(Word(word));
    if (wordObj.questionData.size() > 0) {

        //std::cout << "tstingaddword";
        for (auto& w: wordObj.questionData) {

            if (w.second == idNum) {

                w.first++;

          //      std::cout << "in fiif" << std::endl;
                return;

            }

        }
    }

    wordObj.addQuestionData(1, idNum);
/*
    std::vector<std::pair<int, unsigned long>> vect = wordObj.getQuestionData();
    for (size_t i=0; i<vect.size(); i++)
    {

        std::cout << vect[i].first << " "
             << vect[i].second << std::endl;
    }
*/
}

void HashTableIndex::print()
{
    table.displayTable();
    std::cout << "Total entries: " << table.getNumEntries() << std::endl;
    std::cout << "Total unique words: " << table.getNumUniqueWords() << std::endl;

}
/*
Word &HashTableIndex::getWord(Word& word)
{
    return table.getWord(word);
}
*/
