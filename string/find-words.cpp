#include <iostream>
#include <fstream>

using namespace std;

int main() {
    cout << "Find Words containing the given substring, and print it in the order of alphabet";

    ifstream file("TEXT");

    if (file.is_open()) {
        file.close();
    } else {
        cout << "Fail to open file";
    }

    return 0;
}
