#include "linear_list.h"

linear_list::linear_list() {
    this->len = 100;
    this->count = 0;
    this->elems = new ElemType[this->len];
}

void linear_list::double_capacity(void) {
    ElemType* tmp;
    int newlen;

    newlen = 2 * this->len;
    tmp = new ElemType[newlen];

    memcpy(tmp, this->elems, sizeof(ElemType) * this->len);
    delete[] this->elems;
        
    this->elems = tmp;
}

ElemType linear_list::nth(int index) {
    return this->elems[index];
}

ElemType linear_list::pop(void) {
    ElemType elem = this->elems[this->count - 1];
    this->count--; // 标记为可写即可
    return elem;
}

void linear_list::splice(int index, int howmany) {
    for (int i = index, max = this->count - howmany; i < max; i++) {
        this->elems[i] = this->elems[i + howmany];
    }
    this->count -= howmany;
}

void linear_list::push(ElemType elem) {
    
    this->elems[this->count] = elem;

    this->count++;
    if (this->count == this->len) {
        this->double_capacity();
    }
}
