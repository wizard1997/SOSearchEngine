
#include "catch.hpp"
#include "AVLTree.h"
#include "Word.h"
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include "HashTable.h"


TEST_CASE("AVL Tree", "[AVLTree]") {


    AVLTree<int> tree;
    tree.insert(55);
    tree.insert(2);
    tree.insert(1);
    tree.insert(17);
    tree.insert(9);
    tree.insert(78);
    tree.insert(42);
    tree.insert(3);

    REQUIRE (tree.getCount() == 8);

}
TEST_CASE("Hash Table", "[HashTable]") {

    std::string str = "taco";
    std::string str1 = "taco";
    std::string str2 = "notTaco";
    Word t1(str);
    Word t2(str1);
    Word t3(str2);

    HashTable<Word> htable;
    htable.insert(t1);
    htable.insert(t2);
    htable.insert(t3);

    SECTION ("get word") {

        Word sol = htable.getWord(t3);
        REQUIRE (sol == t3);

    }
    SECTION ("get num entries") {
        REQUIRE (htable.getNumEntries() == 3);
    }
    SECTION ("get num unique words") {
        REQUIRE (htable.getNumUniqueWords() == 2);
    }




}
TEST_CASE("or") {

    std::string s = "str";
    std::string s1 = "taco";
    Word w(s);
    Word w1(s1);

    w.addQuestionData(3, 458947);
    w.addQuestionData(4, 580203);
    w.addQuestionData(2, 679298);

    w1.addQuestionData(8, 458947);
    w1.addQuestionData(6, 123456);
    w1.addQuestionData(3, 248929);
   // w1.addQuestionData(5, 902939);


    Word foo(w.queryNOT(w,w1));

    std::cout << "test" << std::endl;

}
TEST_CASE("") {

    std::string s = "str";
    std::string s1 = "taco";
    std::string s2 = "and";
    Word w(s);
    Word w1(s1);

    w.addQuestionData(3, 458947);
    w.addQuestionData(4, 580203);
    w.addQuestionData(2, 679298);

    std::vector<unsigned long> v  = w.getQuestions();

    std::vector<std::string> queryWords;
    queryWords.push_back(s);
    queryWords.push_back(s1);
    queryWords.push_back(s2);
    queryWords.push_back(s);



}






