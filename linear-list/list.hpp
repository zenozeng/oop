/**
 * @file
 * @author  Zeno Zeng <zenoofzeng@gmail.com>
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * This is my CPP Homework at ZJU.
 */

#ifndef OOP_LIST_H_
#define OOP_LIST_H_

#include "linear_list.hpp"
#include <string>
#include <cstring>

using namespace std;

template <class ElemType>
class list:public linear_list<ElemType>
{
private:
    int len;
    int count;
    ElemType* elems;
    void double_capacity(void); // 双倍线性表的长度

public:
    list();
    int length(void);
    ElemType nth(int index);
    ElemType pop(void);
    void splice(int index, int howmany = 1);
    void push(const ElemType item);
    string join(void);
};


/**
 * Constructor that generate an empty linear list
 *
 */
template<class ElemType>
list<ElemType>::list() {
    this->len = 100;
    this->count = 0;
    this->elems = new ElemType[this->len];
}

/**
 * Double the max length of this linear list
 *
 */
template<class ElemType>
void list<ElemType>::double_capacity(void) {
    ElemType* tmp;
    int newlen;

    newlen = 2 * this->len;
    tmp = new ElemType[newlen];

    memcpy(tmp, this->elems, sizeof(ElemType) * this->len);
    delete[] this->elems;

    this->elems = tmp;
}

/**
 * Get the length of current linear list
 *
 */
template<class ElemType>
int list<ElemType>::length(void) {
    return this->count;
}

/**
 * Get elems[index]
 *
 */
template<class ElemType>
ElemType list<ElemType>::nth(int index) {
    return this->elems[index];
}

/**
 * Removes the last element from linear list and returns that element
 *
 */
template<class ElemType>
ElemType list<ElemType>::pop(void) {
    ElemType elem = this->elems[this->count - 1];
    this->count--; // 标记为可写即可
    return elem;
}

/**
 * Remove the content of an list
 *
 * @param index Index at which to start changing the linear list
 * @param howmany The number of elements to remove
 */
template<class ElemType>
void list<ElemType>::splice(int index, int howmany) {
    for (int i = index, max = this->count - howmany; i < max; i++) {
        this->elems[i] = this->elems[i + howmany];
    }
    this->count -= howmany;
}

/**
 * Add one element to the end of linear list
 *
 */
template<class ElemType>
void list<ElemType>::push(ElemType elem) {

    this->elems[this->count] = elem;

    this->count++;
    if (this->count == this->len) {
        this->double_capacity();
    }
}

/**
 * Join the linear list by comma (C++11 required)
 *
 * @param os Output Stream
 */
template<class ElemType>
string list<ElemType>::join(void) {
    string str = "";
    str += to_string(this->elems[0]);
    for (int i = 1; i < this->count; i++) {
        str += ", ";
        str += to_string(this->elems[i]);
    }
    return str;
}

#endif // OOP_LIST_H_
