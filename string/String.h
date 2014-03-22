#ifndef ZENO_STRING_H
#define ZENO_STRING_H

#include <cstring>
using namespace std;

class String {

private:
    char* chars;
    int len; // length

public:
    String(void);
    String(const char*);
    ~String();
    int length(void);
    int indexOf(char);
    // Lisp Style API
    char first(void);
    String drop(int);
    bool empty(void);
    // todo: substring, indexof, length, 
};

#endif
