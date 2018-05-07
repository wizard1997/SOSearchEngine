#include "catch.hpp"
#include "AVLTree.h"
#include "word.h"
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include "hashtable.h"


TEST_CASE("AVL Tree", "[AVLTree]") {


    //std::cout << "test" << std::endl;

}
TEST_CASE("Hash Table", "[HashTable]") {



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

    std::cout << "tesstiosngaoisngaoingoain";

    std::vector<std::string> queryWords;
    queryWords.push_back(s);
    queryWords.push_back(s1);
    queryWords.push_back(s2);
    queryWords.push_back(s);



}






