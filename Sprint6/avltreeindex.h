#pragma once

#include "AVLTree.h"
#include "indexinterface.h"
#include "word.h"


class AVLTreeIndex : public IndexInterface {


    private:

        AVLTree<Word> tree;
        void saveWord(std::ofstream& outStream, const Word& wordIn);

    public:

        AVLTreeIndex() {std::cout << "avltree construct" << std::endl;}
        //~AVLTreeIndex() {std::cout << "avltree index destructor called" << std::endl;}
        void print();
        void addWord(std::string,unsigned long);
        std::vector<unsigned long> mostFrequentOccurance(Word&);
        std::vector<unsigned long> getQuestionsForWord(Word&);
        Word& getWord(const Word&);
        void saveIndex(std::ofstream&);



};

