#pragma once

#include "hashtable.h"
#include "indexinterface.h"

class HashTableIndex : public IndexInterface
{

    private:

        HashTable<std::string> table;

    public:

        HashTableIndex();
};

