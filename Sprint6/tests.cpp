#include "catch.hpp"
#include "AVLTree.h"
#include <string>
#include <iostream>


TEST_CASE("AVL Tree", "[AVLTree]") {

    AVLTree<std::string> tree1;



    std::cout << "test";

    SECTION("insert/rotation behavior") {

        tree1.insert("abc");
        tree1.insert("abcd");
        tree1.insert("abcde");
        REQUIRE(tree1.getRoot()->element == "abcd");
        tree1.insert("a");
        tree1.insert("ab");
        tree1.insert("abcdef");
        REQUIRE(tree1.getRoot()->left->element == "ab");
        REQUIRE(tree1.getRoot()->right->element == "abcde");
        REQUIRE(tree1.getRoot()->left->left->element == "a");






    }





}

