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
    bool empty(void);
    int length(void);
    int indexOf(char);
    String concat(String);
    String substring(int, int);
};

#endif
