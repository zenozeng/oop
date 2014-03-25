#include <iostream>
#include <fstream>
#include "String.h"

using namespace std;

int main() {
    cout << "Find Words containing the given substring, and print it in the order of alphabet";

    ifstream file("TEXT_SHORT");

    String file_contents;

    String tmp;

    char ch;

    if (file.is_open()) {
        while( !file.eof() ) {
            file >> ch;
            cout << ch << endl;
            cout << "t0" << endl;
            file_contents = file_contents.concat(ch);
            cout << file_contents.to_c_str() << endl;
            cout << "t1" << endl;
        }
        cout << "t2" << endl;
        cout << file_contents.to_c_str() << endl;
        cout << "t3" << endl;
        // file.close();
    } else {
        cout << "Fail to open file";
    }


    cout << "t4" << endl;
    return 0;
}
