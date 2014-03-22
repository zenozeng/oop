// http://richhickey.github.io/clojure-contrib/string-api.html
// http://yige.org/cpp/classes.php

#include <iostream>
using namespace std;

class String {

private:
    int chars;

public:
    String(void);
    String(char []);
    ~String();
    int length(void);
    int indexOf(char);
    // Lisp Style API
    char first(void);
    String drop(int);
    bool empty(void);
    // todo: substring, indexof, length, 
};

// 无参数构造函数
String::String(void) {
}

// Constructor
String::String(char chars[]) {
    
};

// Destructor
String::~String(void) {
};

/* Drops first n characters from string
 *
 * A string should not change its value,
 * thus this method will return a new instance of string.
 * Will return an empty string if n is greater than the length of string.
 */
String String::drop (int n) {
    // TODO 
    return String();
}

//////////////////
//
// Test
//
//////////////////

int main() {
    // String s = "123";
    cout << "Hello World";
    return 0;
}
