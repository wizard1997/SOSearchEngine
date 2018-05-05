#include "catch.hpp"
#include "AVLTree.h"
#include "word.h"
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include "hashtable.h"


TEST_CASE("AVL Tree", "[AVLTree]") {

    AVLTree<int> tree1;
    tree1.insert(20);
    tree1.insert(12);
    tree1.insert(3);
    tree1.insert(17);
    tree1.insert(11);
    tree1.insert(22);
    tree1.insert(16);

    //std::cout << "test" << std::endl;

}
TEST_CASE("Hash Table", "[HashTable]") {



}






