#include "word.h"

Word::Word() {

    stringData = "";
}

Word::Word(unsigned long& num, std::string &str) {
    stringData = str;
}





void Word::setWordStr(std::string &str) {
    stringData = str;
}

std::string& Word::getWordStr() {
    return stringData;
}


