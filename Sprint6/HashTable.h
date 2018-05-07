/** Owner: Jake Watkins **/

#pragma once

#include <iostream>
#include <list>
#include <algorithm>
#include <Word.h>
#include <array>

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

        int LENGTH = 50000; //Size of the hashtable
        int numEntries; //How many times insert has been called
        int numUniqueWords; //How many unique words are in the table
        std::list<T>* table;

    public:

        HashTable();
        ~HashTable() {}
        T& insert(const T& key);
        void printFile(std::ofstream& outStream);

        void remove(T);
        void resize();
        int hash(std::string str) const;
        void clear();
        void displayTable();

        bool exists(T key, size_t index);
        T& getWord(T key);

        int getNumEntries() const;
        int getNumUniqueWords() const;
};


template<typename T>
int HashTable<T>::getNumEntries() const
{
    return numEntries;
}

template<typename T>
int HashTable<T>::getNumUniqueWords() const
{
    return numUniqueWords;
}

template<typename T>
HashTable<T>::HashTable()
{

    table = new std::list<T>[LENGTH];
    numEntries = 0;
    numUniqueWords = 0;

}

/**
 *  Hashes and then inserts the key into its assigned index
 **/
template<typename T>
T& HashTable<T>::insert(const T& key)
{

    //Create a string that can be hashed from the input data
    std::string keyWord = key.getWordStr();
    size_t index = std::hash<std::string>()(keyWord);
    index = index % LENGTH;

    //If it's already inserted return a reference to that element
    //in the table
    if (exists(key, index)) {

        numEntries++;
        return getWord(key);

    }

    //Else add the element to the table and return a reference to it
    table[index].push_back(key);
    numUniqueWords++;
    numEntries++;

    return getWord(key);

}

template<typename T>
void HashTable<T>::printFile(std::ofstream &outStream)
{
    for (int i = 0; i < LENGTH; i++) {

        for (auto& x : table[i]) {
            outStream << x.getWordStr() << " ";
            for (auto& y: x.questionData) {
                outStream << y.second << " " << y.first << " ";
            }
            outStream << std::endl;
        }
    }
}

template<typename T>
void HashTable<T>::remove(T key)
{

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

    }
}

template<typename T>
void HashTable<T>::resize()
{
    int oldLength = LENGTH;
    LENGTH *= LENGTH;
    HashTable<T> tempTable;

    for (int i = 0; i < oldLength; i++) {

        std::fill_n(tempTable, LENGTH, nullptr);

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
int HashTable<T>::hash(std::string str) const
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

/**
 * Funcion that returns a boolean variable.
 * True if the element already exists in the table, false
 * if it doesn't
 */
template<typename T>
bool HashTable<T>::exists(T key, size_t index)
{

    for (auto& iter : table[index]) {

        if (iter == key) {


            return true;

        }

    }
    return false;

}

/**
 *
 *  Find a word in the hash table and return a reference
 *  to it
 *
 **/
template<typename T>
T& HashTable<T>::getWord(T key)
{

    std::string keyWord = key.getWordStr();
    size_t index = std::hash<std::string>()(keyWord);
    index = index % LENGTH;

    for (auto& iter : table[index]) {

        if (iter == key) {

            return iter;

        }

    }


}
