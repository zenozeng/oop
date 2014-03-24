#include "String.h"
#include <iostream>

using namespace std;

void test();

int main() {
    cout << ">>>> String Class Test\n";
    cout << ">> 简单构造 / C风格字符串构造";
    String str("This is my String class. ");
    cout << ">> 无参数构造";
    String str2;
    cout << ">> 下标访问";
    cout << str.charAt(0);
    
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
