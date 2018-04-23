#pragma once

#include <iostream>
#include <list>

template<typename T>
class HashTable {

    private:

        class HashEntry {

            public:

                T data;
                T key;
                HashEntry* chain; //To be used for chaining

                HashEntry(T& dataEntry, T& keyEntry)
                    : data(dataEntry), key(keyEntry) {}

        };

        int LENGTH = 5;

        int numBuckets;
        //HashEntry** table;
        std::list<T>* table;

    public:

        HashTable();

        void insert(std::string);
        int hash(std::string str);


        void displayTable();
};


template<typename T>
HashTable<T>::HashTable()
{
    table = new std::list<T>[LENGTH];
}

template<typename T>
void HashTable<T>::insert(std::string key)
{
    int hashedVal = hash(key);
    table[hashedVal].push_back(key);
}

/**
 * Shoutout to http://www.cse.yorku.ca/~oz/hash.html for hash function help.
 *
 * Hashes a string and returns an integer which will be the index for the key based on str
 * @param str the string to be hashed
 * @return  and int containing where the key should go
 */
template<typename T>
int HashTable<T>::hash(std::string str)
{
    unsigned long hash = 5381; //Prime number

    for(int i = 0; i < (int)str.length(); i++) {
        hash = ((hash << 5) + hash) + str[i];
    }

    return hash % LENGTH;
}

template<typename T>
void HashTable<T>::displayTable()
{
    for (int i = 0; i < LENGTH; i++) {
        std::cout << i;

        for (auto x : table[i])
            std::cout << " --> " << x;

        std::cout << std::endl;
    }
}
