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
                HashEntry(T& dataEntry, T& keyEntry)
                    : data(dataEntry), key(keyEntry) {}

        };

        int LENGTH = 5; //Size of the hashtable

        int numEntries; //How many times insert has been called
        std::list<T>* table;

    public:

        HashTable();
        ~HashTable() {}
        void insert(T);
        void remove(T);
        int hash(T);
        void clear();
        void displayTable();
};


template<typename T>
HashTable<T>::HashTable()
{
    table = new std::list<T>[LENGTH];
}

/**
 *  Hashes and then inserts the key into its assigned index
 **/
template<typename T>
void HashTable<T>::insert(T key)
{
    int index = hash(key);
    table[index].push_back(key);
    numEntries++; //increments how many entries have occured
}

template<typename T>
void HashTable<T>::remove(T key)
{
//typename std::list<T>::iterator i = table[index].begin()
    int index = hash(key);
    typename std::list<T>::iterator i;
    for (i = table[index].begin(); i != table[index].end(); ++i) {

        if (*i == key) {
            break;
        }
    }
    if (i != table[index].end()){

        std::cout << "outside for loop in 2nd if\n\n";
        i = table[index].erase(i);

        //table[index].remove(key);

    }
}

/**
 * Shoutout to http://www.cse.yorku.ca/~oz/hash.html for hash function help.
 *
 * Hashes a string and returns an integer which will be the index for the key based on str
 * @param str the string to be hashed
 * @return  and int containing where the key should go
 */
template<typename T>
int HashTable<T>::hash(T str)
{
    unsigned long hash = 5381; //Prime number

    for(int i = 0; i < (int)str.length(); i++) {
        hash = ((hash << 5) + hash) + str[i];
    }

    return hash % LENGTH;
}

template<typename T>
void HashTable<T>::clear()
{

    for (int i = 0; i < LENGTH; i++)
        table[i].clear();

}

/**
 *  Function that displays the hashtable, really only used for
 *  rudimentary testing
 **/
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
