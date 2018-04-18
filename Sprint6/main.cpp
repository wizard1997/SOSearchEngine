#include <iostream>
#include <cstring>
#include "fileparser.h"
#include "porter2_stemmer.h"
#include "AVLTree.h"

<<<<<<< HEAD
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
=======

int main(int argc, char* argv[]) {
    std::cout << "Hello World!" << std::endl;

    std::ios_base::sync_with_stdio(false);
    FileParser fp1;
    fp1.test();

    std::string test = "running";
    std::string test1 = "JAckE/@@d";
    Porter2Stemmer::stem(test);
    Porter2Stemmer::trim(test1);
    Porter2Stemmer::stem(test1);
    std::cout << test << std::endl;
    std::cout << test1 << std::endl;

    fp1.parseQuestionFile(argv[1]);
>>>>>>> ffa6b9294713d97af3fbe18fff8dfdcd8409b682
}
