#include "String.h"
#include <cassert>
#include <cstdlib>
#include <iostream>

using namespace std;

#define test(name, exp) assert(exp); \
    cout << "PASS TEST: " << name << "\n"

int main() {
    const char* chars = "This is my String class.";
    cout << ">>>> String Class Test\n";

    cout << "\n>>> Constructor Test\n";
    cout << ">> Constructor(void)\n";
    String str_without_arg;
    cout << ">> Constructor(const char*)\n";
    String str(chars);
    cout << ">> Copy Constructor\n";
    String str2(str);

    cout << "\n>>> Method Test\n";
    test("empty", str.empty() == false && str_without_arg.empty() == true);
    test("charAt", str.charAt(0) == 'T');
    test("indexOf(char* pattern)", str.indexOf("his") == 1);
    test("indexOf(char* pattern, int start)", str.indexOf("is", 3) == 5);
    String search("his");
    test("indexOf(String pattern)", str.indexOf(search) == 1);
    test("to_c_str", strcmp(chars, str.to_c_str()) == 0);
    test("substring", strcmp(str.substring(0, 4).to_c_str(), "This") == 0);
    test("length", str.length() == strlen(chars));
    test("compare", str.compare("This is") > 0 && str.compare("Z") < 0 && str.compare(chars) == 0);

    return 0;
}
