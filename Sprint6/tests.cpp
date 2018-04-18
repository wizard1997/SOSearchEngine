#include "catch.hpp"
#include "AVLTree.h"
#include <cstring>


TEST_CASE("AVL Tree", "[AVLTree]") {

    AVLTree<string> tree1;
    tree1.insert("abc");
    tree1.insert("abcd");
    tree1.insert("abcde");
    tree1.insert("a");
    tree1.insert("ab");
    tree1.insert("abcede");


    std::cout << "test";


    SECTION("List behavior"){

        REQUIRE(list.at(0)->data == 0);
        REQUIRE(list.at(3)->data == 3);
        REQUIRE(list.at(1)->next->data == 2);
        REQUIRE(list.at(6)->previous->data == 5);
        list.remove(9);
        REQUIRE(list.at(8)->data == 8);
        list.insertBack(9);




    }

}


