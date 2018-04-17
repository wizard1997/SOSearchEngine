#include <iostream>
#include "fileparser.h"
#include "porter2_stemmer.h"

using namespace std;

int main() {
    cout << "Hello World!" << endl;


    FileParser fp1;
    fp1.test();

    string test = "running";
    string test1 = "JAckE/@@d";
    Porter2Stemmer::stem(test);
    Porter2Stemmer::trim(test1);
    Porter2Stemmer::stem(test1);
    cout << test << endl;
    cout << test1 << endl;
}
