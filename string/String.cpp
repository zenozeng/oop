#include <cstdlib>
#include "String.h"


// 无参数构造函数
String::String() {
    this->len = 0;
    this->chars = NULL;
}

// 拷贝构造
String::String(const String& str) {
    this->len = str.len;
    this->chars = new char[this->len + 1];
    memcpy(this->chars, str.chars, sizeof(char)*(this->len + 1));
}

// Constructor
// String str("123");
String::String(const char* chars) {
    this->len = strlen(chars);
    // 这里必须要拷贝一份才安全，否则可能遭遇修改
    this->chars = new char[this->len + 1]; // 这里包括 c style string 里最后的 \0
    for(int i = 0; i <= this->len; ++i) {
        this->chars[i] = chars[i];
    }
};

// Destructor
String::~String() {
    if(this->chars) {
        delete this->chars;
    }
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

// todo: 越界？
char String::charAt (int index) {
    if(index >= (this->len)) {
        return '\0';
    }
    return this->chars[index];
}

int String::indexOf(char ch, int start = 0) {

    for (int i = start; i < this->len; ++i) {
        if(ch == this->chars[i]) {
            return i;
        }
    }

    return -1;
}

int String::indexOf(const char* pattern) {

    int pattern_len = strlen(pattern);

    for (int i = 0; i < (this->len - pattern_len); ++i) {
        for (int j = 0; j < pattern_len; ++j) {
            if (pattern[j] != this->chars[i+j]) {
                ++i;
                j = 0;
            } else {
                if (j == (pattern_len - 1)) {
                    return i;
                }
            }
        }
    }

    return -1;
}

int String::indexOf(String str) {

    // 对str，这里调用的是拷贝构造函数
    // 若无拷贝构造函数则会直接复制内存，则析构函数会报错会被重复调用
    
    return this->indexOf( str.to_c_str() );
}
