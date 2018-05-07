/** Owner: Jake Watkins **/

#include "HashTableIndex.h"


/**
 *
 * @brief HashTableIndex::addWord Adds a word to the hash table
 *
 * @param word The string of the Word to be inserted into the table
 * @param idNum The question ID that this word is in
 *
 */
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





Word& HashTableIndex::getWord(const Word& word)
{
    return table.getWord(word);
}

void HashTableIndex::saveIndex(std::ofstream& outStream) {

    table.printFile(outStream);


}

void HashTableIndex::insert(Word& wordIn)
{
    table.insert(wordIn);
}
