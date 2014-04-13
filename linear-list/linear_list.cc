#include "linear_list.h"

/**
 * @file
 * @author  Zeno Zeng <zenoofzeng@gmail.com>
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * This is my CPP Homework at ZJU.
 */


/**
 * Constructor that generate an empty linear list
 *
 */
linear_list::linear_list() {
    this->len = 100;
    this->count = 0;
    this->elems = new ElemType[this->len];
}

/**
 * Double the max length of this linear list
 *
 */
void linear_list::double_capacity(void) {
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
int linear_list::length(void) {
    return this->count;
}

/**
 * Get elems[index]
 *
 */
ElemType linear_list::nth(int index) {
    return this->elems[index];
}

/**
 * Removes the last element from linear list and returns that element
 *
 */
ElemType linear_list::pop(void) {
    ElemType elem = this->elems[this->count - 1];
    this->count--; // 标记为可写即可
    return elem;
}

/**
 * Remove the content of an array
 *
 * @param index Index at which to start changing the linear list
 * @param howmany The number of elements to remove
 */
void linear_list::splice(int index, int howmany) {
    for (int i = index, max = this->count - howmany; i < max; i++) {
        this->elems[i] = this->elems[i + howmany];
    }
    this->count -= howmany;
}

/**
 * Add one element to the end of linear list
 *
 */
void linear_list::push(ElemType elem) {
    
    this->elems[this->count] = elem;

    this->count++;
    if (this->count == this->len) {
        this->double_capacity();
    }
}
