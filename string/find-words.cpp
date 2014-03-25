#include <iostream>
#include <fstream>
#include "String.h"

using namespace std;

int main() {
    cout << "Find Words containing the given substring, and print it in the order of alphabet";

    ifstream file("TEXT");

    String file_contents;

    char ch;

    if (file.is_open()) {
        while( !file.eof() ) {
            file >> ch;
            file_contents = file_contents.concat(ch);
        }
        file.close();
    } else {
        cout << "Fail to open file";
    }

    cout << file_contents.to_c_str();

    return 0;
}
