#include "AVLTreeIndex.h"



void AVLTreeIndex::print()
{
    std::cout << "In avlIndex print" << std::endl;
}

void AVLTreeIndex::addWord(std::string word,unsigned long idNum)
{

    Word& inplaceWord = tree.insert(Word(word));
    if (inplaceWord.questionData.size() > 0) {

        for (auto& w: inplaceWord.questionData) {


            if (w.second == idNum) {

                w.first++;
                return;
            }
        }

    }

    inplaceWord.addQuestionData(1,idNum);

}




Word& AVLTreeIndex::getWord(const Word& wordIn) {


    return (tree.access(wordIn));

}

void AVLTreeIndex::saveIndex(std::ofstream& outStream) {


    tree.printFile(outStream);

}

void AVLTreeIndex::insert(Word& wordIn) {

    tree.insert(wordIn);


}

