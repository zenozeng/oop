/**
 * @file
 * @author  Zeno Zeng <zenoofzeng@gmail.com>
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * This is my CPP Homework at ZJU.
 */

#ifndef OOP_ARRAY_H_
#define OOP_ARRAY_H_

#include "linear_list.hpp"
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

template <class ElemType>
class array:public linear_list<ElemType>
{
private:
    int len;
    int count;
    ElemType* elems;
    void double_capacity(void); // 双倍线性表的长度

public:
    array();
    ~array();
    int length(void);
    ElemType nth(int index);
    ElemType pop(void);
    void remove(int index, int howmany = 1);
    void push(ElemType item);
    void insert(const int index, const ElemType elem);
    string join(void);
};


/**
 * Constructor that generate an empty array
 *
 */
template<class ElemType>
array<ElemType>::array() {
    this->len = 100;
    this->count = 0;
    this->elems = new ElemType[this->len];
}

template<class ElemType>
array<ElemType>::~array() {
    delete[] this->elems;
}

/**
 * Double the max length of this array
 *
 */
template<class ElemType>
void array<ElemType>::double_capacity(void) {
    ElemType* tmp;
    int newlen;

    newlen = 2 * this->len;
    tmp = new ElemType[newlen];

    memcpy(tmp, this->elems, sizeof(ElemType) * this->len);
    delete[] this->elems;

    this->elems = tmp;
    this->len = newlen;
}

/**
 * Get the length of current array
 *
 */
template<class ElemType>
int array<ElemType>::length(void) {
    return this->count;
}

/**
 * Get elems[index]
 *
 */
template<class ElemType>
ElemType array<ElemType>::nth(int index) {
    return this->elems[index];
}

/**
 * Removes the last element from array and returns that element
 *
 */
template<class ElemType>
ElemType array<ElemType>::pop(void) {
    ElemType elem = this->elems[this->count - 1];
    this->count--; // 标记为可写即可
    return elem;
}

/**
 * Remove the content of an array
 *
 * @param index Index at which to start changing the array
 * @param howmany The number of elements to remove
 */
template<class ElemType>
void array<ElemType>::remove(int index, int howmany) {
    for (int i = index, max = this->count - howmany; i < max; i++) {
        this->elems[i] = this->elems[i + howmany];
    }
    this->count -= howmany;
}

/**
 * Insert an item to at given index
 *
 */
template<class ElemType>
void array<ElemType>::insert(int index, ElemType elem) {
    ElemType lastItem = this->elems[this->count - 1];
    for (int i = this->count - 1; i > index; i--) {
        this->elems[i] = this->elems[i - 1];
    }
    this->elems[index] = elem;
    this->push(lastItem); // note that cout will be added here
}

/**
 * Add one element to the end of array
 *
 */
template<class ElemType>
void array<ElemType>::push(ElemType elem) {

    if (this->count == this->len) {
        this->double_capacity();
    }

    this->elems[this->count] = elem;
    this->count++;
}

/**
 * Join the array by comma (C++11 required)
 *
 * @param os Output Stream
 */
template<class ElemType>
string array<ElemType>::join(void) {
    string str = "";
    str += to_string(this->elems[0]);
    for (int i = 1; i < this->count; i++) {
        str += ", ";
        str += to_string(this->elems[i]);
    }
    return str;
}

#endif // OOP_ARRAY_H_
