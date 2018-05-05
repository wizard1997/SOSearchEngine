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


        return Catch::Session().run();


    } else if (argc > 1 && strcmp(argv[1], "-p") == 0) {

        std::string str = "store";
        Word w(str);
        FileParser fp1(argv[2]);

        fp1.runMenu();

        fp1.indexhandler.index->print();
        fp1.indexhandler.index->getWord(w);
        fp1.indexhandler.index->mostFrequentOccurance(w);

    } else {


        std::cout << "Invalid flag input" << std::endl;


    }



}
