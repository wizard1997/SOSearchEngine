#include "IndexHandler.h"

IndexHandler::IndexHandler(char* choiceIn) {

    std::string indexChoice(choiceIn);
    if (indexChoice == "tree") {


        index = new AVLTreeIndex;
    }

}
