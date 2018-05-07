#define CATCH_CONFIG_RUNNER

#include "HashTableIndex.h"
#include "IndexInterface.h"
#include <iostream>
#include <cstring>
#include "catch.hpp"
#include "FileProcessor.h"
#include "porter2_stemmer.h"
#include "AVLTree.h"
#include "HashTable.h"
#include "QueryProcessor.h"



int main(int argc, char* argv[]) {

    //run tests
    if (argc > 1 && strcmp(argv[1], "-t") == 0) {


        return Catch::Session().run();

    //parse files
    } else if (argc > 1 && strcmp(argv[1], "-p") == 0) {


        FileProcessor fp1(argv[2]);

        fp1.runMenu();

    //search for words
    } else if (argc > 1 && strcmp(argv[1], "-s") == 0) {

        QueryProcessor qp1;
        qp1.runQuery();

    //bad input
    } else {

        std::cout << "Invalid flag input" << std::endl;

    }




}
