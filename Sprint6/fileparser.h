#pragma once

#include <unordered_set>
#include <iostream>
#include <vector>
#include <fstream>
#include <list>
#include <sstream>
#include <cstring>
#include <porter2_stemmer.h>
#include "MemoryMapped.h"
#include "AVLTree.h"
#include "hashtable.h"
#include <dirent.h>
#include "IndexHandler.h"

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



        AVLTree<std::string> tree;
        HashTable<std::string> table;
        IndexHandler indexhandler;


        void parseQuestionFile(std::string file);
        void parseTagFile(); //TODO
        bool selectDetectedFile();
        bool selectDataType;
        void parseString(std::string& stringIn);
        void parseAllValidFiles();

        void runMenu();
        static bool isStopWord(std::string& word);

};

