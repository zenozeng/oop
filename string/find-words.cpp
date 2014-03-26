#include <iostream>
#include <cstdio>
#include "String.h"

using namespace std;

// Config
String pattern = "ro";
String target_file = "target.txt";

int main() {
    cout << "Find Words containing the given substring," << endl << " and print it in the order of alphabet" << endl;


    String file_contents;

    char ch;

    FILE * pFile;

    // note that operator >> will eat all whitespace
    // so use fopen and fgetc here

    pFile = fopen(target_file.to_c_str(), "r");
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

    cout << ">> File loaded." << endl;

    String* words;
    words = new String[10000];
    int count = 0;

    int cursor = 0; // 游标
    int occur = file_contents.indexOf(pattern, cursor);
    int last_occur = -1;
    while(occur != -1 && occur != last_occur) {
        String word = file_contents.getword(occur);
        cout << endl << "Find `" << pattern.to_c_str() << "` in `" << word.to_c_str() << "`";

        // push to array
        bool exists = false;
        for(int i = 0; i < count; ++i) {
            String str = words[i];
            if(str.compare(word) == 0) {
                exists = true;
            }
        }
        if(exists) {
            cout << " (already exists)";
        } else {
            words[count] = word;
            ++count;
        }

        // update cursor to the end + 1 of word
        int index_in_word = word.indexOf(pattern);
        int word_length = word.length();
        int pattern_occur = occur;
        cursor = pattern_occur + word_length + index_in_word;

        // update occur
        last_occur = occur;
        occur = file_contents.indexOf(pattern, cursor);
    }
    cout << endl << ">> Find " << count << " in total.";

    // sort words
    for(int i = 0; i < count; ++i) {
        for(int j = i + 1; j < count; ++j) {
            if(words[i].compare(words[j]) > 0) {
                String tmp = words[i];
                words[i] = words[j];
                words[j] = tmp;
            }
        }
    }

    // output words
    for(int i = 0; i < count; ++i) {
        cout << endl << i + 1 << ". " << words[i].to_c_str();
    }
    return 0;
}
