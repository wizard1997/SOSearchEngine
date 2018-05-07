/** Owner: Addison Kimball **/

#pragma once

#include <unordered_set>
#include <iostream>
#include <vector>
#include <fstream>
#include <list>
#include <sstream>
#include <cstring>
#include <string>
#include <porter2_stemmer.h>
#include "MemoryMapped.h"
#include "AVLTree.h"
#include "HashTable.h"
#include <dirent.h>
#include "IndexHandler.h"
#include "QueryProcessor.h"

class FileProcessor
{
    private:

        //List of stop words
        static std::unordered_set<std::string> stopWords;

        std::vector<std::string> fileVec;
        void selectDetectedFile(size_t);


        //vector containing each of the questions relevant words
       // std::vector<std::pair<int,std::string> questions;

    public:


        FileProcessor(std::string dirIn);

        IndexHandler indexhandler;


        void parseQuestionFile(std::string file);
        void parseTagFile(); //TODO
        bool selectDetectedFile();
        bool selectDataType;
        void parseString(std::string& stringIn,unsigned long idNum);
        void parseAllValidFiles();
        bool scanFile(std::string file, unsigned long idNum);

        void displayQuestion(unsigned long);
        void runMenu();
        static bool isStopWord(std::string& word);

};

