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
    cout << ">> 简单构造 / C风格字符串构造";
    String str(chars);
    cout << ">> 无参数构造\n";
    String str2;
    test("下标访问", str.charAt(0) == 'T');
    cout << ">> C风格字符串\n";
    cout << "\n";
    cout << strcmp(str.to_c_str(), chars);
    cout << "\n";
    assert(strcmp(str.to_c_str(), chars) == 0);
    cout << "\n";
    cout << ">> Substring Test\n";
    cout << str.substring(0, 7).to_c_str();
    cout << ">> Compare Test\n";
    cout << str.compare(str.substring(0, 7));
    cout << ">> IndexOf Test\n";
    cout << str.indexOf("his");
    return 0;
}
