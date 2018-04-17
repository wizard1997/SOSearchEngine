#include <iostream>
#include "fileparser.h"
#include "porter2_stemmer.h"

using namespace std;

int main() {
    cout << "Hello World!" << endl;


    string test = "running";
    string test1 = "jacked";
    Porter2Stemmer::stem(test);
    Porter2Stemmer::stem(test1);
    cout << test << endl;
    cout << test1 << endl;

}
