#define CATCH_CONFIG_RUNNER

#include <iostream>
#include <cstring>
#include "catch.hpp"
#include "fileparser.h"
#include "porter2_stemmer.h"
#include "AVLTree.h"

using namespace std;

int main(int argc, char* argv[]) {

    if (argc > 1 && strcmp(argv[1], "-t") == 0) {


            return Catch::Session().run();


        } else if (argc > 1 && strcmp(argv[1], "-c") == 0) {



        } else {
            cout << "Invalid flag, check arguments" << endl;
            return 1;
        }

}
