#include <iostream>
#include <cstdio>
#include "String.h"

using namespace std;

int main() {
    cout << "Find Words containing the given substring," << endl << " and print it in the order of alphabet" << endl;


    String file_contents;

    char ch;

    FILE * pFile;

    cout << "init> " << file_contents.length() << endl;
    
    // note that operator >> will eat all whitespace
    // so use fopen and fgetc here

    pFile = fopen("TEXT_SHORT", "r");
    if (pFile == NULL) {
        perror("Fail to open file");
    } else {
        ch = fgetc(pFile);
        file_contents = file_contents.concat(ch);
        while(ch != EOF) {
            ch = fgetc(pFile);
            int ascii = (int)ch;
            if(ascii >= 0) {
                // ignore negative ascii chars
                file_contents = file_contents.concat(ch);
            }
        }
    }

    cout << file_contents.length() << endl;
    cout << file_contents.to_c_str() << endl;

    cout << "File loaded." << endl;

    int cursor = 0; // 游标
    String pattern = "cd";
    int occur = file_contents.indexOf(pattern, cursor);
    int last_occur = -1;
    while(occur != -1 && occur != last_occur) {
        String word = file_contents.getword(occur);
        cout << "FIND::" << word.to_c_str() << endl;

        // update cursor to the end + 1 of word
        int index_in_word = word.indexOf(pattern);
        int word_length = word.length();
        int pattern_occur = occur;
        cursor = pattern_occur + word_length + index_in_word;

        // update occur
        last_occur = occur;
        occur = file_contents.indexOf(pattern, cursor);
    }
    return 0;
}
