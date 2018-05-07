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



};

