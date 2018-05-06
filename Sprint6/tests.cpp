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

    w.addQuestionData(1, 458949);
    w.addQuestionData(4, 580203);
    w.addQuestionData(2, 679298);
    w.addQuestionData(8, 902939);

    w1.addQuestionData(6, 123456);
    w1.addQuestionData(3, 248929);
    w1.addQuestionData(5, 902939);


    Word testW(s);
    //testW = testW.queryOR(w,w1);
    testW = testW.queryAND(w,w1);


    std::cout << "test" << std::endl;

}






