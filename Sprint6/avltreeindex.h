#pragma once

#include "AVLTree.h"
#include "indexinterface.h"
#include "word.h"


class AVLTreeIndex : public IndexInterface {


    private:

        AVLTree<Word> tree;

    public:

        AVLTreeIndex() {std::cout << "avltree construct" << std::endl;}
        //~AVLTreeIndex() {std::cout << "avltree index destructor called" << std::endl;}

        void addWord(std::string,unsigned long);
       // Word& getWord(Word&);



};

