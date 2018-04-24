#include "word.h"

Word::Word()
{
    questionID = 0;
    stringData = "";
}

Word::Word(unsigned long& num, std::string &str)
{
    questionID = num;
    stringData = str;
}

void Word::setQuestionID(unsigned long &num)
{
    questionID = num;
}

unsigned long& Word::getQuestionID()
{
    return questionID;
}

void Word::setWordStr(std::string &str)
{
    stringData = str;
}

std::string& Word::getWordStr()
{
    return stringData;
}


