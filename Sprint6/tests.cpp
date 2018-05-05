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
TEST_CASE("frequency") {

    std::string str = "fortnite";
    Word t(str);
    t.addQuestionData(3, 803202);
    t.addQuestionData(5, 732920);
    t.addQuestionData(24, 829839);

    Word w(123456,str);
    w.addQuestionID(987654);
    w.addQuestionID(7576384);
    std::vector<unsigned long> vec;
    vec = t.getMostFrequent(t.getQuestionData());

    //std::vector<unsigned long> v = w.getQuestions();
    std::cout << w;

    std::cout << "end";


}






