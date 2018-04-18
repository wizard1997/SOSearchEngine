#pragma once

#include <unordered_set>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

class FileParser
{
    private:

        //List of stop words
        static std::unordered_set<std::string> stopWords;

        //vector containing each of the questions relevant words
        std::vector<std::string> questions;

    public:
        FileParser();

        void parseQuestionFile(std::string file);
        void parseTagFile();

        static bool isStopWord(std::string& word);
        void test(); //not a function to be included in final submission
};

