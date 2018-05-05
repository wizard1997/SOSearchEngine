#include "word.h"


Word::Word(std::string &str)
    : stringData(str) {

}

Word::Word(const Word& wordIn)
    : stringData(wordIn.getWordStr()) {


    questionData = wordIn.questionData;
}

Word::~Word()
{
    if (!questionData.empty())
        questionData.clear();
}

/**
 * @brief Word::addQuestionData Adds the question ID and
 * how many times that word appears in that particular
 * question
 *
 * @param freq How many times the Word appears in the question
 *
 * @param id Question ID
 **/
void Word::addQuestionData(int freq, unsigned long id)
{
    questionData.push_back(std::make_pair (freq, id) );
}

void Word::setWordStr(const std::string& str)
{
    stringData = str;
}



/**
 * @brief Word::getMostFrequent Function that finds the questions
 * where the Word is used most frequently
 *
 * @param inputVectData The questionData vec from a Word
 *
 * @return A vector of question IDs sorted so that the first element
 * in the vector is the question where the Word is most common. Descending order
 **/
std::vector<std::pair<int, unsigned long>> Word::getMostFrequent()
{
    //Vector to be returned
    std::vector<std::pair<int, unsigned long>> sortedIDVec;

    //Sorts the vector pair and inserts the ID number into the return vector
    std::sort(questionData.begin(), questionData.end(), std::greater<>());
    int i = 0;
    for (auto& q: questionData) {

        i++;
        if (i > 10) {

            break;
        }
        sortedIDVec.push_back(std::make_pair (questionData[i].first, questionData[i].second) );

    }

    return sortedIDVec;

}

std::string Word::getWordStr() const
{
    return stringData;
}

bool Word::operator==(const Word& rhs) const
{
    return stringData == rhs.getWordStr();
}

bool Word::operator!=(const Word &rhs) const
{
    return stringData != rhs.getWordStr();
}

Word &Word::operator=(const Word &input)
{
    stringData = input.stringData;
    questionData = input.questionData;
    return *this;
}

bool Word::operator>(const Word &rhs) const
{
    return stringData > rhs.getWordStr();
}

bool Word::operator<(const Word &rhs) const
{
    return stringData < rhs.getWordStr();
}


