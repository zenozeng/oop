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

    cout << "\n>>> 构造测试\n";
    cout << ">> 无参数构造\n";
    String str_without_arg;
    cout << ">> C风格字符串构造\n";
    String str(chars);
    cout << ">> 拷贝构造\n";
    String str2(str);

    cout << "\n>>> 函数测试\n";
    test("empty", str.empty() == false && str_without_arg.empty() == true);
    test("charAt", str.charAt(0) == 'T');
    test("substring (char*)", str.indexOf("his") == 1);
    String search("his");
    test("substring (String)", str.indexOf(search) == 1);
    test("to_c_str", strcmp(chars, str.to_c_str()) == 0);
    test("length", str.length() == strlen(chars));
    test("Compare", str.compare("This is") > 0 && str.compare("Z") < 0 && str.compare(chars) == 0);

    return 0;
}
