#include "IndexHandler.h"

IndexHandler::IndexHandler() {


     index = nullptr;


}
/*
IndexHandler::~IndexHandler() {

    if (index) {

        delete index;
    }

}


bool IndexHandler::selectDS() {

    std::string indexChoice(choiceIn);
    if (indexChoice == "tree") {


        index = new AVLTreeIndex;

    } else if (indexChoice == "table") {


        index = new HashTableIndex;

    } else {


        std::cout << "\nNo valid data structure selected.";
        index = nullptr;
    }



}
*/
