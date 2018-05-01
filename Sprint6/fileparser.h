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

class FileParser
{
    private:

        //List of stop words
        static std::unordered_set<std::string> stopWords;
        AVLTree<std::string> tree;
        HashTable<std::string> table;
        std::list<std::string> fileList;


        //vector containing each of the questions relevant words
       // std::vector<std::pair<int,std::string> questions;

    public:
        FileParser(std::string dirIn);

        void parseQuestionFile(std::string file);
        void parseTagFile();

        void parseString(std::string& stringIn);

        static bool isStopWord(std::string& word);
        void test(std::string); //not a function to be included in final submission
};

