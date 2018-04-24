#pragma once

#include <unordered_set>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstring>
#include <porter2_stemmer.h>
#include "MemoryMapped.h"
#include "AVLTree.h"

class FileParser
{
    private:

        //List of stop words
        static std::unordered_set<std::string> stopWords;
        AVLTree<std::string> tree;

        //vector containing each of the questions relevant words
       // std::vector<std::pair<int,std::string> questions;

    public:
        FileParser();

        void parseQuestionFile(std::string file);
        void parseTagFile();

        void parseString(std::string& stringIn);

        static bool isStopWord(std::string& word);
        void test(std::string); //not a function to be included in final submission
};

