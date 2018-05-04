#pragma once

#include "AVLTree.h"
#include "indexinterface.h"
#include "word.h"


class AVLTreeIndex : public IndexInterface {


    private:

        AVLTree<Word> tree;

    public:

        AVLTreeIndex();

        void addWord(std::string,unsigned long);
        Word& getWord(Word&);



};

