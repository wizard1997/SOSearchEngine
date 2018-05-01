#include "word.h"

Word::Word()
{
    stringData = "";
}

Word::Word(unsigned long num, std::string &str)
{
    questionsContainingWord.push_back(num);
    stringData = str;
}

Word::~Word()
{
    questionsContainingWord.clear();
}

void Word::addQuestionID(unsigned long num)
{
    questionsContainingWord.push_back(num);
}

std::vector<unsigned long> Word::getQuestions() const
{
    return questionsContainingWord;
}

void Word::setWordStr(const std::string& str)
{
    stringData = str;
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
    questionsContainingWord = input.questionsContainingWord;
    totalFrequency = input.totalFrequency;
}


