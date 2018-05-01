#include "word.h"

Word::Word() {

    stringData = "";
}

Word::Word(unsigned long num, std::string &str)
{
    questionsContainingWord.push_back(num);
    stringData = str;
}

void Word::addQuestionID(unsigned long num)
{
    questionsContainingWord.push_back(num);
}

std::vector<unsigned long> Word::getQuestions()
{
    return questionsContainingWord;
}

void Word::setWordStr(std::string &str)
{
    stringData = str;
}

std::string& Word::getWordStr()
{
    return stringData;
}

Word &Word::operator=(Word & input)
{

}


