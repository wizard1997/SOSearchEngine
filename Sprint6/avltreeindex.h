#pragma once

#include "AVLTree.h"
#include "indexinterface.h"
#include "word.h"


class AVLTreeIndex : public IndexInterface {


    private:

        AVLTree<Word> tree;

    public:

        AVLTreeIndex();

        void addWord(Word&);
        Word& getWord(Word&);



};

