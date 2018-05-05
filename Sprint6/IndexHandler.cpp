#include "IndexHandler.h"
#include "avltreeindex.h"
#include "hashtableindex.h"

IndexHandler::IndexHandler() {


     index = nullptr;


}

IndexHandler::~IndexHandler() {

    if (index) {

        delete index;
    }

}


bool IndexHandler::selectDS() {

    while (true) {


        std::cout << "--------------------------------------------------------------\n"
                     "1. AVL Tree\n"
                     "2. Hash Table\n"
                     "Welcome! Please select which data structure you wish to use: ";
        int indexChoice = 0;
        std::cin >> indexChoice;
        if (indexChoice == 1) {


            index = new AVLTreeIndex;
            return false;

        } else if (indexChoice == 2) {


            index = new HashTableIndex;
            return false;

        } else {


            std::cout << "\nNo valid data structure selected.";
            index = nullptr;
            return true;
        }

    }



}

