#pragma once

#include "AVLTree.h"
#include "IndexInterface.h"
#include "Word.h"


class AVLTreeIndex : public IndexInterface {


    private:

        AVLTree<Word> tree;
        void saveWord(std::ofstream& outStream, const Word& wordIn);

    public:

        AVLTreeIndex() {std::cout << "avltree construct" << std::endl;}
        void print();
        void addWord(std::string,unsigned long);
        Word& getWord(const Word&);
        void saveIndex(std::ofstream&);



};

