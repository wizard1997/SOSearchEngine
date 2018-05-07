#pragma once

#include "indexinterface.h"
#include <boost/serialization/vector.hpp>
#include <boost/serialization/utility.hpp>

class IndexHandler
{
    public:

        IndexHandler();
        ~IndexHandler();
        IndexHandler(char*);
        IndexInterface* index;


        bool selectDS();
        void saveIndex(std::string filePath);
        void loadIndex();


};

