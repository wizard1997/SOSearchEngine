#include <iostream>
#include "fileparser.h"
#include "porter2_stemmer.h"

using namespace std;

int main() {
    cout << "Hello World!" << endl;


    FileParser fp1;
    fp1.test();
    return 0;


    string test = "running";
    string test1 = "jacked";
    Porter2Stemmer::stem(test);
    Porter2Stemmer::stem(test1);
    cout << test << endl;
    cout << test1 << endl;
}
