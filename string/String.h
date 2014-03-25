#ifndef ZENO_STRING_H
#define ZENO_STRING_H

#include <cstring>
using namespace std;

class String {

private:
    char* chars;
    int len;

public:
    String();
    String(const char*);
    String(const String&);
    ~String();
    bool empty();
    int length();
    char charAt(int);
    int indexOf(char, int);
    int indexOf(const char*);
    int indexOf(String);
    int compare(String);
    int compare(const char*);
    const char* to_c_str();
    String substring(int, int);
};

#endif
