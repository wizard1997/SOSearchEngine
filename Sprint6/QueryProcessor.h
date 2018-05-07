#pragma once

#include <iostream>
#include "Word.h"
#include "IndexInterface.h"
#include "FileProcessor.h"
#include "IndexHandler.h"
#include "porter2_stemmer.h"


class QueryProcessor
{
    private:

    public:
        QueryProcessor();
        bool isBoolQuery(std::string);


        IndexHandler indexhandler;
        void runQuery();

        //Functions to process query booleans
        void runAND(std::vector<std::string>);
        void runOR(std::vector<std::string>);
        void runNOT(std::string, std::string);
        void runNOTadvanced(std::vector<std::string>, std::string, std::string);

        //Helper functions in case there is another bool query with a NOT
        Word runHelperAND(std::vector<std::string>);
        Word runHelperOR(std::vector<std::string>);


};

