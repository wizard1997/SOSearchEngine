#include "IndexHandler.h"
#include "AVLTreeIndex.h"
#include "HashTableIndex.h"



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


void IndexHandler::saveIndex(std::string filePath) {

    std::ofstream outStream;
    outStream.open(filePath, std::ios::trunc);
    if (!outStream.is_open()) {


        std::cout << "\nUnable to save index to file specified." << std::endl;
        return;

    } else {


        index->saveIndex(outStream);


    }


}

