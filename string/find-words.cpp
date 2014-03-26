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
        cout << "Loading File" << endl;
        while( !file.eof() ) {
            file >> ch;
            file_contents = file_contents.concat(ch);
        }
        cout << file_contents.to_c_str() << endl;
        file.close();
    } else {
        cout << "Fail to open file";
    }

    int cursor = 0; // 游标
    int len = file_contents.length();
    String pattern = "pro";
    while(cursor < len) {
        find = file_contents.indexOf(pattern, cursor);
        if(find != -1) {
            // look back to get the word
            // todo: get_word_by_index: get the word which contains the index, should return String
        }
        ++cursor;
    }
    return 0;
}
