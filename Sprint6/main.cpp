#include <iostream>
#include "fileparser.h"
#include "porter2_stemmer.h"


int main(int argc, char* argv[]) {
    std::cout << "Hello World!" << std::endl;

    std::ios_base::sync_with_stdio(false);
    FileParser fp1;
    fp1.test();

    std::string test = "running";
    std::string test1 = "JAckE/@@d";
    Porter2Stemmer::stem(test);
    Porter2Stemmer::trim(test1);
    Porter2Stemmer::stem(test1);
    std::cout << test << std::endl;
    std::cout << test1 << std::endl;

    fp1.parseQuestionFile(argv[1]);
}
