#pragma once

#include <unordered_set>
#include <iostream>


class FileParser
{
    private:

        //List of stop words
        static std::unordered_set<std::string> stopWords;

    public:
        FileParser();

        static bool isStopWord(std::string& word);
        void test();
};

