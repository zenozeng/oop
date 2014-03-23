// http://richhickey.github.io/clojure-contrib/string-api.html
// http://yige.org/cpp/classes.php

#include <iostream>
#include "String.h"


// 无参数构造函数
String::String(void) {
    this->len = 0;
    this->chars = NULL;
}

// Constructor
String::String(const char* chars) {

    this->len = strlen(chars);

    this->chars = new char[this->len]; // 这里不存 c style string 里最后的 \0
    
    for(int i = 0; i < this->len; ++i) {
        this->chars[i] = chars[i];
    }
};

// Destructor
String::~String(void) {
};

bool String::empty (void) {
    return this->len == 0;
}

/* Drops first n characters from string
 *
 * A string should not change its value,
 * thus this method will return a new instance of string.
 * Will return an empty string if n is greater than the length of string.
 */
String String::substring (int start, int end) {
    // TODO 
    return String();
}

//////////////////
//
// Test
//
//////////////////

int main() {
    String s("123");
    cout << "Hello World 3";
    return 0;
}
