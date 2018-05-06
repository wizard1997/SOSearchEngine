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
#include "hashtable.h"
#include <dirent.h>
#include "IndexHandler.h"
#include "queryprocessor.h"

class FileParser
{
    private:

        //List of stop words
        static std::unordered_set<std::string> stopWords;

        std::vector<std::string> fileVec;
        void selectDetectedFile(size_t);


        //vector containing each of the questions relevant words
       // std::vector<std::pair<int,std::string> questions;

    public:


        FileParser(std::string dirIn);

        IndexHandler indexhandler;


        void parseQuestionFile(std::string file);
        void parseTagFile(); //TODO
        bool selectDetectedFile();
        bool selectDataType;
        void parseString(std::string& stringIn,unsigned long idNum);
        void parseAllValidFiles();

        bool isBoolQuery(std::string str);

        void runMenu();
        static bool isStopWord(std::string& word);

};

