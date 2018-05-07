/** Owner: Jake Watkins **/

#include "Word.h"


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

        ++i;
        if (i > 10) {

            break;

        }
        sortedIDVec.push_back(std::make_pair (q.first, q.second) );

    }

    return sortedIDVec;

}

std::vector<unsigned long> Word::getQuestions()
{
    std::vector<unsigned long> returnVect;
    for (auto& q: questionData) {

        returnVect.push_back(q.second);

    }
    return returnVect;
}

/**
 *
 * @brief Word::queryOR Function that creates a new word to
 * return that has the data from the two words in the
 * parameter. OR means questions that have the first word or the
 * second word, or both.  Also increments frequency based on how
 * often each word occurs in the question.
 *
 * @param firstWord Word to be ORed
 *
 * @param secondWord Other Word to be ORed
 *
 * @return A word with the correct document information of ORed words
 *
 **/
Word Word::queryOR(Word firstWord, Word secondWord)
{

    Word returnWord(firstWord.stringData);

    if (firstWord.questionData.size() > secondWord.questionData.size()) {

        for (size_t i = 0; i < secondWord.questionData.size(); i++) {

            returnWord.addQuestionData(firstWord.questionData[i].first, firstWord.questionData[i].second);
            returnWord.addQuestionData(secondWord.questionData[i].first, secondWord.questionData[i].second);

        }

    } else if (firstWord.questionData.size() < secondWord.questionData.size()) {

        for (size_t i = 0; i < firstWord.questionData.size(); i++) {

            returnWord.addQuestionData(firstWord.questionData[i].first, firstWord.questionData[i].second);
            returnWord.addQuestionData(secondWord.questionData[i].first, secondWord.questionData[i].second);

        }

    } else {

        for (size_t i = 0; i < firstWord.questionData.size(); i++) {

            returnWord.addQuestionData(firstWord.questionData[i].first, firstWord.questionData[i].second);
            returnWord.addQuestionData(secondWord.questionData[i].first, secondWord.questionData[i].second);

        }

    }
    if (returnWord.questionData.size() < firstWord.questionData.size()) {
        return firstWord;
    }
    if (returnWord.questionData.size() < secondWord.questionData.size()) {
        return secondWord;
    }
    return returnWord;

}

/**
 *
 * @brief Word::queryAND Handles the process of ANDing two words. This
 * means all of the questions that contain the first word AND the second
 * word.
 *
 * @param firstWord First word to be ANDed
 * @param secondWord Other word to be ANDed
 *
 * @return A word with the AND data of the two words inputed
 *
 **/
Word Word::queryAND(Word firstWord, Word secondWord)
{

    Word returnWord(firstWord.stringData);
    unsigned long newFreq;

    if (firstWord.questionData.size() > secondWord.questionData.size()) {

        for (size_t i = 0; i < secondWord.questionData.size(); i++) {

            //For loop to iterate through the firstWord questionData to see if any of the questions
            //are the same as this index of the second
            for (size_t j = 0; j < firstWord.questionData.size(); j++) {

                if (secondWord.questionData[i].second == firstWord.questionData[j].second) {

                    newFreq = firstWord.questionData[j].first + secondWord.questionData[i].first;
                    returnWord.addQuestionData(newFreq, secondWord.questionData[i].second);

                }

            }

        }

    } else if (firstWord.questionData.size() < secondWord.questionData.size()) {

        for (size_t i = 0; i < firstWord.questionData.size(); i++) {

            for (size_t j = 0; j < secondWord.questionData.size(); j++) {

                if (firstWord.questionData[i].second == secondWord.questionData[j].second) {

                    newFreq = secondWord.questionData[j].first + firstWord.questionData[i].first;
                    returnWord.addQuestionData(newFreq, firstWord.questionData[i].second);

                }

            }

        }

    } else if (firstWord.questionData.size() == secondWord.questionData.size()) {

        for (size_t i = 0; i < firstWord.questionData.size(); i++) {

            for (size_t j = 0; j < secondWord.questionData.size(); j++) {

                if (firstWord.questionData[i].second == secondWord.questionData[j].second) {

                    newFreq = secondWord.questionData[j].first + firstWord.questionData[i].first;
                    returnWord.addQuestionData(newFreq, firstWord.questionData[i].second);

                }

            }

        }


    }

    //If there are no AND occurences of two Words return
    if (returnWord.questionData.empty())
        returnWord.addQuestionData(0,000000);


    return returnWord;
}

/**
 *
 * @brief Word::queryNOT Handles the function of finding the questions
 * that include one word but not another.
 *
 * @param keepWord The word that we want to see in the question
 * @param notWord The word we don't want to see in the question
 *
 * @return A word containing only the questions containg the keep Word
 * and not the not word
 *
 **/
Word Word::queryNOT(Word keepWord, Word notWord)
{
    bool isMatch = false;
    Word returnWord(keepWord.stringData);

    for (size_t i = 0; i < keepWord.questionData.size(); i++) {

        for (size_t j = 0; j < notWord.questionData.size(); j++) {

            if (keepWord.questionData[i].second == notWord.questionData[j].second) {

                isMatch = true;

            }
        //std::cout << "testing this fucking NOT query ";
        }
        if (!isMatch) {
            returnWord.addQuestionData(keepWord.questionData[i].first, keepWord.questionData[i].second);
        }
        isMatch = false;

    }


    return returnWord;

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


