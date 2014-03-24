#include <iostream>
#include "String.h"


// 无参数构造函数
String::String() {
    this->len = 0;
    this->chars = NULL;
}

// Constructor
// C风格字符串构造函数
String::String(char* chars) {
    this->len = strlen(chars);
    this->chars = chars;
}

// Constructor
// String str("123");
String::String(const char* chars) {

    this->len = strlen(chars);

    this->chars = new char[this->len + 1]; // 这里包括 c style string 里最后的 \0
    
    for(int i = 0; i <= this->len; ++i) {
        this->chars[i] = chars[i];
    }
};

// Destructor
String::~String() {
    delete this->chars;
};

// Return true if the string is empty.
bool String::empty () {
    return this->len == 0;
}

// Note: 当类被析构，这个指针就不见了
const char* String::to_c_str () {
    return this->chars;
}

/* Return the length of the string.
 *
 * Note that the \0 is ignored.
 */
int String::length () {
    return this->len;
}

int String::compare (String str) {
    return strcmp(this->chars, str.to_c_str());
}

String String::substring (int start, int end = -1) {

    char* chars;

    if (end == -1 || end > this->len) {
        end = this->len;
    }

    chars = new char[end - start];

    for (int i = start; i < end; ++i) {
        chars[i] = this->chars[i];
    }

    return String(chars);
}

//////////////////
//
// Test
//
//////////////////

int main() {
    cout << ">> String Class Test\n";
    String str("This is my String class. ");
    cout << str.to_c_str();
    cout << "\n";
    cout << ">> Substring Test\n";
    cout << str.substring(0, 7).to_c_str();
    cout << ">> Compare Test\n";
    cout << str.compare(str.substring(0, 7));
    return 0;
}
