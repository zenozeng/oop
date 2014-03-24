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
    String(const char*);
    String(const String&);
    ~String();
    bool empty();
    int length();
    int indexOf(char, int);
    int bm_search(char*, int, char*, int);
    int indexOf(const char*);
    int indexOf(String);
    int compare(String);
    const char* to_c_str();
    String concat(String);
    String substring(int, int);
};

#endif
