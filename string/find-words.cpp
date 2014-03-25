#include <iostream>
#include <fstream>
#include "String.h"

using namespace std;

int main() {
    cout << "Find Words containing the given substring, and print it in the order of alphabet";

    ifstream file("TEXT");

    char* line;

    String file_content;

    if (file.is_open()) {
        file.close();
    } else {
        cout << "Fail to open file";
        while (getline (file, line)) {
            file_content.concat(line);
        }
    }

    return 0;
}
