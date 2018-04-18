#include <iostream>
#include <cstring>
#include "fileparser.h"
#include "porter2_stemmer.h"
#include "AVLTree.h"

using namespace std;

int main(int argc, char* argv[]) {

    if (argc > 1 && strcmp(argv[1], "-t") == 0) {

            AVLTree<string> tree1;
            tree1.insert("abc");
            tree1.insert("abcd");
            tree1.insert("abcde");
            tree1.insert("a");
            tree1.insert("ab");
            tree1.insert("abcede");


            std::cout << "test";

        } else if (argc > 1 && strcmp(argv[1], "-c") == 0) {



        } else {
            cout << "Invalid flag, check arguments" << endl;
            return 1;
        }

}
