/** Owner: Addison Kimball **/

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
        outStream.close();

    }


}

bool IndexHandler::loadIndex() {


    std::ifstream inStream;
    inStream.open("output.dat");
    if (!inStream.is_open()) {

        std::cout << "Unable to load index file. Is 'output.dat' missing?" << std::endl;
        return false;

    } else {

        std::string wordLine;
        while (std::getline(inStream,wordLine)) {
            wordLine += '\n';
            auto done = wordLine.end();
            auto begin = wordLine.begin();
            auto end = wordLine.begin();
            end = std::find(begin,done,' ');
            std::string wordstring(wordLine.begin(),end);
            Word temp(wordstring);
            begin = end+1;
            while (end <= done) {

                end = std::find(begin,done,' ');
                std::string idString(begin,end);
                unsigned long id = atoi(idString.c_str());
                begin = end+1;
                end = std::find(begin,done,' ');
                std::string freqString(begin,end);
                begin = end+1;
                unsigned long freq = atoi(freqString.c_str());
                if ((freq > 0) && (id > 0)) {

                    temp.addQuestionData(freq,id);
                }
                if (*begin == '\n') {

                    break;
                }

            }
            index->insert(temp);


        }




    }

    return true;
}

