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
    int len = file_contents.length();
    String pattern = "cd";
    int occur = -2;
    int last_occur = -3;
    while(occur != -1 && occur != last_occur) {
        cout << "occur:" << occur << " last:" << last_occur << endl;
        
        last_occur = occur;
        occur = file_contents.indexOf(pattern, cursor);
        String word = file_contents.getword(cursor);
        cout << word.to_c_str() << endl;
        cursor += word.length();

        cout << ">> occur:" << occur << " last:" << last_occur << endl;
    }
    return 0;
}
