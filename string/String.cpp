#include <cstdlib>
#include "String.h"

/**
 * @file
 * @author  Zeno Zeng <zenoofzeng@gmail.com>
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * This is my CPP Homework at ZJU.
 * Note that this is an Immutable String Implementation.
 * You can not change current String but you can get a new String.
 */
 
/**
 * Constructor that generate an empty string
 *
 */
String::String() {
    this->len = 0;
    this->chars = new char[1];
    this->chars[0] = '\0';
}

/**
 * Copy Constructor
 *
 */
String::String(const String& str) {
    this->len = str.len;
    this->chars = new char[this->len + 1]; // 这里包括 c style string 里最后的 \0
    memcpy(this->chars, str.chars, sizeof(char)*(this->len + 1));
}

/**
 * Constructor for C Style string
 *
 */
String::String(const char* chars) {
    this->len = strlen(chars);
    // 这里必须要拷贝一份才安全，否则可能遭遇修改
    this->chars = new char[this->len + 1]; // 这里包括 c style string 里最后的 \0
    memcpy(this->chars, chars, sizeof(char) * (this->len + 1));
};

/**
 * Destructor
 *
 */
String::~String() {
    delete this->chars;
};

/**
 * Return true if the string is empty.
 *
 */
bool String::empty () {
    return this->len == 0;
}

/**
 * Return C Style String
 *
 * @note If the class descructor was called, this->chars will be deleted.
 *       You should copy the chars to avoid issues.
 */
const char* String::to_c_str () {
    return this->chars;
}

/**
 * Return the length of the string
 *
 * @note the \0 is ignored
 */
int String::length () {
    return this->len;
}

/**
 * Similar to strcmp(this->chars, str2)
 *
 */
int String::compare (String str) {
    return strcmp(this->chars, str.to_c_str());
}

/**
 * Similar to strcmp(this->chars, str2)
 *
 */
int String::compare (const char* chars) {
    return strcmp(this->chars, chars);
}

/**
 * Substring extracts characters from start up to but not including end
 *
 * @note If end is omitted, it is treated as if it were this->len.
 *       If end is greater than this->len, it is treated as if it were this->len.
 */
String String::substring (int start, int end = -1) {

    char* chars;

    if (end == -1 || end > this->len) {
        end = this->len;
    }

    chars = new char[end - start + 2];

    for (int i = start; i < end; ++i) {
        chars[i] = this->chars[i];
    }
    chars[end - start + 1] = '\0';

    return String(chars);
}

/**
 * Return char at given index
 *
 * @note If index is greater than this->len, \0 will be returned.
 */
char String::charAt (int index) {
    if(index >= (this->len)) {
        return '\0';
    }
    return this->chars[index];
}

int String::indexOf(const char* pattern, int start = 0) {

    int pattern_len = strlen(pattern);

    for (int i = start; i < (this->len - pattern_len); ++i) {
        for (int j = 0; j < pattern_len; ++j) {
            if (pattern[j] != this->chars[i+j]) {
                break;
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
    // 若无拷贝构造函数则会直接复制内存，则析构函数会报错，
    // 因为那些指针指向的 delete 会被重复调用
    
    return this->indexOf( str.to_c_str() );
}
