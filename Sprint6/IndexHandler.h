#pragma once

#include "indexinterface.h"


class IndexHandler
{
    public:

        IndexHandler();
        ~IndexHandler();
        IndexHandler(char*);
        IndexInterface* index;


        bool selectDS();


};

