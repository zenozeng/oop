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
 * Constructor for assignment
 *
 */
String& String::operator=(const String& str) {
    if(this != &str) {
        // 原先的值已经不再需要
        delete[] this->chars;

        this->len = str.len;
        this->chars = new char[this->len + 1];
        memcpy(this->chars, str.chars, sizeof(char) * (this->len + 1));
    }

    // *this 是这个 String Object，
    // 最后返回时自动将这个 Object 转换为了 reference
    return *this;
}

/**
 * Copy Constructor
 *
 */
String::String(const String& str) {
    this->len = str.len;
    this->chars = new char[this->len + 1]; // 这里包括 c style string 里最后的 \0
    memcpy(this->chars, str.chars, sizeof(char) * (this->len + 1));
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
    delete[] this->chars;
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
 */
int String::length () {
    return this->len;
}

/**
 * Combines the text and returns a new string.
 *
 */
String String::concat (const char ch) {
    int new_len = this->len + 1;
    char* new_chars;
    new_chars = new char[new_len + 1];
    memcpy(new_chars, this->chars, sizeof(char) * (this->len));
    new_chars[new_len - 1] = ch;
    new_chars[new_len] = '\0';
    String str(new_chars);
    delete[] new_chars;
    return str;
}

/**
 * Combines the text and returns a new string.
 *
 */
String String::concat (const char* chars) {
    int new_len = this->len + strlen(chars);
    char* new_chars;
    new_chars = new char[new_len + 1];
    memcpy(new_chars, this->chars, sizeof(char) * (this->len));
    for(int i = 0; i <= strlen(chars); ++i) {
        new_chars[i + this->len] = chars[i];
    }
    String str(new_chars);
    delete[] new_chars;
    return str;
}

/**
 * Combines the text and returns a new string.
 *
 */
String String::concat (String str) {
    return this->concat(str.chars);
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

    int len = end - start;

    chars = new char[len + 1];

    for (int i = 0; i < len; ++i) {
        chars[i] = this->chars[i + start];
    }

    chars[len] = '\0';

    return String(chars);
}

/**
 * Return true if the char match `a-zA-Z'`
 *
 * @note About `'`, it is not included yet. To write, make sure it's not the beg nor end.
 * @private
 */
bool String::is_valid_char_of_word (char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

/**
 * Get the first word whose end index >= fromIndex
 *
 * @param fromIndex The index to start the search from. The default value is 0.
 *
 * @note if we are at the middle of a word, it will look back to get the whole word.
 * @note a word should only contains `a-zA-Z'`
 */
String String::getword (int fromIndex) {

    char ch;
    int cursor = fromIndex;
    int start;
    int end; // note that end is not included

    ch = this->chars[cursor];
    if(this->is_valid_char_of_word(ch)) {
        // we may at the beginning or middle of a word
        // go backward to get where the word starts
        while(cursor > -1 && (this->is_valid_char_of_word(ch))) {
            --cursor;
            ch = this->chars[cursor];
        }
        // we are at the whitespace right before the word, forward 1 char now
        ++cursor;
        ch = this->chars[cursor];
        // set start of word
        start = cursor;
    } else {
        // go forward to get where the word starts
        while(cursor < (this->len - 1) && (!this->is_valid_char_of_word(ch))) {
            ++cursor;
            ch = this->chars[cursor];
        }
        start = cursor;
    }
    // go forward to get where the word ends
    while(cursor < this->len && this->is_valid_char_of_word(ch)) {
        ++cursor;
        ch = this->chars[cursor];
    }
    end = cursor;
    return this->substring(start, end);
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

/**
 * Return the index of the first occurrence of the search value.
 * Returns -1 if the value is not found.
 *
 * @param pattern The search value.
 * @param start The index to start the search from. The default value is 0.
 */
int String::indexOf(const char* pattern, int start) {

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

/**
 * Return the index of the first occurrence of the search value.
 * Returns -1 if the value is not found.
 *
 * @param str The search value.
 * @param start The index to start the search from. The default value is 0.
 */
int String::indexOf(String str, int start) {

    // 对str，这里调用的是拷贝构造函数
    // 若无拷贝构造函数则会直接复制内存，则析构函数会报错，
    // 因为那些指针指向的 delete 会被重复调用
    
    return this->indexOf( str.to_c_str() , start );
}
