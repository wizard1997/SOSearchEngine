#include "hashtableindex.h"



void HashTableIndex::addWord(std::string word, unsigned long idNum)
{
    Word &wordObj = table.insert(Word(word));
    if (wordObj.questionData.size() > 0) {

        for (auto& w: wordObj.questionData) {

            if (w.second == idNum) {

                w.first++;

                return;

            }

        }
    }

    wordObj.addQuestionData(1, idNum);
}

void HashTableIndex::print()
{
    table.displayTable();
    std::cout << "Total entries: " << table.getNumEntries() << std::endl;
    std::cout << "Total unique words: " << table.getNumUniqueWords() << std::endl;

}

std::vector<unsigned long> HashTableIndex::mostFrequentOccurance(Word& word)
{
    //std::vector<unsigned long> returnVect = word.getMostFrequent(word.questionData);
    //return returnVect;
    word.getMostFrequent();
}

std::vector<unsigned long> HashTableIndex::getQuestionsForWord(Word& word)
{

}

Word& HashTableIndex::getWord(const Word& word)
{
    return table.getWord(word);
}

void HashTableIndex::saveIndex(std::ofstream&) {

}
