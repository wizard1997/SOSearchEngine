#define CATCH_CONFIG_RUNNER

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



        FileParser fp1(argv[2]);

        bool run = true;
        while (run) {

            run = fp1.selectDetectedFile();

        }


    } else {


        std::cout << "Invalid flag input" << std::endl;


    }



}
