#include "avltreeindex.h"

void AVLTreeIndex::addWord(std::string word,unsigned long idNum)
{

    Word inplaceWord = tree.insert(Word(word));
    for (auto& w: inplaceWord.getQuestionData()) {


        if (w.second() == idNum) {

            w.first()++;
            return;
        }
    }
    inplaceWord.getQuestionData().insert(std::make_pair(1,idNum);

}

Word& AVLTreeIndex::getWord(Word &)
{

}
