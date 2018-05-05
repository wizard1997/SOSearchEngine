#define CATCH_CONFIG_RUNNER

#include "hashtableindex.h"
#include "indexinterface.h"
#include <iostream>
#include <cstring>
#include "catch.hpp"
#include "fileparser.h"
#include "porter2_stemmer.h"
#include "AVLTree.h"
#include "hashtable.h"



int main(int argc, char* argv[]) {

    if (argc > 1 && strcmp(argv[1], "-t") == 0) {

        std::string str = "fortnite";
        std::string str1 = "lol";
        unsigned long num = 123345;
        unsigned long num1 = 298342;

        IndexInterface* x = new HashTableIndex;
        x->addWord(str, num);
        x->addWord(str, num);
        x->addWord(str1, num);
        x->addWord(str, num1);


        std::cout << "test";
        //return Catch::Session().run();


    } else if (argc > 1 && strcmp(argv[1], "-p") == 0) {



        FileParser fp1(argv[2]);

        bool run = true;
        while (run) {

            run = fp1.selectDetectedFile();

        }


    } else {


        std::cout << "Invalid flag input" << std::endl;


    }



}
