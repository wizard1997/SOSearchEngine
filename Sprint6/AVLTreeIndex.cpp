/** Owner: Addison Kimball **/

#include "AVLTreeIndex.h"


/**
 * @brief AVLTreeIndex::print Prints the tree using a preorder traversal
 *
 *
 **/
void AVLTreeIndex::print()
{
    tree.printInOrder();
}

/**
 * @brief AVLTreeIndex::addWord Combines the word string
 * with the question id, constructing and inserting, or getting reference to item
 * in tree. Allows for adding instances of word without duplicates to tree.
 *
 * @param word Word string object
 *
 * @param idNum Question ID number
 **/
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



/**
 * @brief AVLTreeIndex::getWord Gets reference to word object input as param.
 *
 * @param wordIn const word object reference to search for.
 **/
Word& AVLTreeIndex::getWord(const Word& wordIn) {


    return (tree.access(wordIn));

}

/**
 * @brief AVLTreeIndex::saveIndex Save off index serialized to data file.
 *
 * @param outStream std::ofstream& object to print out to file with.
 **/
void AVLTreeIndex::saveIndex(std::ofstream& outStream) {


    tree.printFile(outStream);


}


/**
 * @brief AVLTreeIndex::insert Different from add word, inserts fully formed
 * word object rather than constructing it.
 *
 * @param wordIn  word object reference to insert.
 **/
void AVLTreeIndex::insert(Word& wordIn) {

    tree.insert(wordIn);


}

