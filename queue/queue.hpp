/**
 * @file
 * @author  Zeno Zeng <zenoofzeng@gmail.com>
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * This is my CPP Homework at ZJU.
 */

#ifndef OOP_QUEUE_H_
#define OOP_QUEUE_H_

#include <cstring>
#include <exception>

using namespace std;

class queue_invalid_state_exception: public exception
{
    virtual const char* what() const throw()
        {
            return "Fail to deque an empty queue";
        }
} invalid_state_exception;

template <class ElemType> class queue {
private:
    int len;
    int count;
    ElemType* elems;
    void double_capacity(void); // 双倍线性表的长度

public:
    queue();
    ~queue();
    int length(void);
    void enque(ElemType);
    ElemType deque(void);
    bool is_empty(void);
};


/**
 * Constructor that generate an empty queue
 *
 */
template<class ElemType>
queue<ElemType>::queue() {
    this->len = 100;
    this->count = 0;
    this->elems = new ElemType[this->len];
}

template<class ElemType>
queue<ElemType>::~queue() {
    delete[] this->elems;
}

template<class ElemType>
bool queue<ElemType>::is_empty(void) {
    return this->count < 1;
}

/**
 * Double the max length of this queue
 *
 */
template<class ElemType>
void queue<ElemType>::double_capacity(void) {
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
 * Get the length of current queue
 *
 */
template<class ElemType>
int queue<ElemType>::length(void) {
    return this->count;
}

/**
 * Removes the first element from queue and returns that element
 *
 */
template<class ElemType>
ElemType queue<ElemType>::deque(void) {
    if (this->count < 1) {
        throw invalid_state_exception;
    }
    ElemType elem = this->elems[0];
    for (int i = 0; i < (this->count - 1); i++) {
        this->elems[i] = this->elems[i+1];
    }
    this->count--;
    return elem;
}

/**
 * Add one element to the end of queue
 *
 */
template<class ElemType>
void queue<ElemType>::enque(ElemType elem) {

    if (this->count == this->len) {
        this->double_capacity();
    }

    this->elems[this->count] = elem;
    this->count++;
}

#endif // OOP_QUEUE_H_
