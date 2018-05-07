/** Owner: Addison Kimball **/

#pragma once

#include "AVLTree.h"
#include "IndexInterface.h"
#include "Word.h"


class AVLTreeIndex : public IndexInterface {


    private:

        AVLTree<Word> tree;
        //private version of saveWord
        void saveWord(std::ofstream& outStream, const Word& wordIn);

    public:


        //constructors
        AVLTreeIndex() {}
        //access
        Word& getWord(const Word&);
        void print();
        //modify
        void addWord(std::string,unsigned long);
        void insert(Word &);
        //index persistence
        void saveIndex(std::ofstream&);

};

