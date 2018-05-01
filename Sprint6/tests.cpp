#include "catch.hpp"
#include "AVLTree.h"
#include "word.h"
#include <iostream>
#include <cstring>
#include <string>


TEST_CASE("AVL Tree", "[AVLTree]") {

    AVLTree<int> tree1;
    tree1.insert(20);
    tree1.insert(12);
    tree1.insert(3);
    tree1.insert(17);
    tree1.insert(11);
    tree1.insert(22);
    tree1.insert(16);

    std::cout << "test";

}

TEST_CASE("Word class", "[Word") {

    SECTION("overloading operators") {

        std::string str = "taco";
        std::string str1 = "taco";
        std::string str2 = "notTaco";

        Word t1(2463918, str);
        Word t2(8584894, str1);
        REQUIRE(t1 == t2);

    }
}

/*
    SECTION("List behavior"){

        REQUIRE(tree1.at(0)->data == 0);
        REQUIRE(list.at(3)->data == 3);
        REQUIRE(list.at(1)->next->data == 2);
        REQUIRE(list.at(6)->previous->data == 5);
        list.remove(9);
        REQUIRE(list.at(8)->data == 8);
        list.insertBack(9);

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
*/





