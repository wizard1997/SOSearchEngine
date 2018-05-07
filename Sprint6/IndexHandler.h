/** Owner: Addison Kimball **/

#pragma once

#include "IndexInterface.h"



class IndexHandler
{
    public:

        IndexHandler();
        ~IndexHandler();
        IndexHandler(char*);
        IndexInterface* index;


        bool selectDS();
        void saveIndex(std::string filePath);


        bool loadIndex();
};

