// http://richhickey.github.io/clojure-contrib/string-api.html
// http://yige.org/cpp/classes.php

class String {

private:
    int chars;

public:
    int length(void);
    int indexOf(char ch);
    String drop(int n);
    // todo: substring, indexof, length, 
};

/* Drops first n characters from string
 *
 * A string should not change its value,
 * thus this method will return a new instance of string.
 * Will return an empty string if n is greater than the length of string.
 */
String String::drop (int n) {
}
