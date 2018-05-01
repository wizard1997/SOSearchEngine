#define CATCH_CONFIG_RUNNER

#include <iostream>
#include <cstring>
#include "catch.hpp"
#include "fileparser.h"
#include "porter2_stemmer.h"
#include "AVLTree.h"
#include "hashtable.h"

//"/home/coder/Code/2015-questions.psv"
int main(int argc, char* argv[]) {

    if (argc > 1 && strcmp(argv[1], "-t") == 0) {


         return Catch::Session().run();


    } else if (argc > 1 && strcmp(argv[1], "-p") == 0) {


        FileParser fp1(argv[2]);
        fp1.parseQuestionFile(argv[2]);


    } else {

        HashTable<std::string> h;
        int num = 17;
        std::string str1 = "abc";
        std::string str2 = "zad";
        std::string str3 = "cal";
        std::string str4 = "girl";
        std::string str5 = "taco";
        std::string str6 = "mosquito";
        std::string str7 = "delaware";
        std::string str8 = "doc";
        std::string str9 = "fortnite";
        h.insert(str);
        h.insert(str1);
        h.insert(str2);
        h.insert(str3);
        h.insert(str4);
        h.insert(str5);
        h.insert(str6);
        h.insert(str7);
        h.insert(str8);
        h.insert(str9);
        h.displayTable();
        h.clear();
        std::cout << "cleared\n\n";
        h.displayTable();
    }



}
