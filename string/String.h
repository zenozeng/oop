#ifndef ZENO_STRING_H
#define ZENO_STRING_H

#include <cstring>
using namespace std;

class String {

private:
    char* chars;
    int len; // length

public:
    String();
    String(char*);
    String(const char*);
    ~String();
    bool empty();
    int length();
    int indexOf(char);
    const char* to_c_str();
    String concat(String);
    String substring(int, int);
};

#endif
