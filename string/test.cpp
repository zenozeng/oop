#include "String.h"
#include <iostream>

using namespace std;

int main() {
    cout << ">> String Class Test\n";
    String str("This is my String class. ");
    cout << str.to_c_str();
    cout << "\n";
    cout << ">> Substring Test\n";
    cout << str.substring(0, 7).to_c_str();
    cout << ">> Compare Test\n";
    cout << str.compare(str.substring(0, 7));
    cout << ">> IndexOf Test\n";
    cout << str.indexOf("his");
    return 0;
}
