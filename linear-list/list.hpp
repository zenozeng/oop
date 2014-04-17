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
#include <iostream>

using namespace std;

/**
 * List Node
 *
 */

template <class ElemType>
class node
{
public:
    node(ElemType elem);
    node* next;
    node* prev;
    ElemType value;
};

template <class ElemType>
node<ElemType>::node(ElemType value) {
    this->value = value;
    this->next = NULL;
    this->prev = NULL;
}

/**
 * List
 *
 */

template <class ElemType>
class list:public linear_list<ElemType>
{
private:
    int count;
    node<ElemType>* head;
    node<ElemType>* foot;

public:
    list();
    int length(void);
    ElemType nth(int index);
    ElemType pop(void);
    void remove(int index, int howmany = 1);
    void push(ElemType item);
    void insert(int index, ElemType elem);
    string join(void);
};


/**
 * Constructor that generate an empty list
 *
 */
template<class ElemType>
list<ElemType>::list() {
    this->count = 0;
    this->head = NULL;
    this->foot = NULL;
}

/**
 * Get the length of current list
 *
 */
template<class ElemType>
int list<ElemType>::length(void) {
    return this->count;
}

/**
 * Add one element to the end of list
 *
 */
template<class ElemType>
void list<ElemType>::push(ElemType elem) {

    node<ElemType>* elem_node;
    elem_node = new node<ElemType>(elem);

    if(this->head == NULL) {
        this->head = elem_node;
        this->foot = elem_node;
    } else {
        elem_node->prev = this->foot;
        this->foot->next = elem_node;
        this->foot = elem_node;
    }

    this->count++;
}

/**
 * Get elems[index]
 *
 */
template<class ElemType>
ElemType list<ElemType>::nth(int index) {
    node<ElemType>* current = this->head;
    while( index != 0 ) {
        current = current->next;
        index--;
    }
    return current->value;
}

/**
 * Removes the last element from list and returns that element
 *
 */
template<class ElemType>
ElemType list<ElemType>::pop(void) {
    node<ElemType>* foot = this->foot;
    ElemType last = foot->value;
    this->foot = this->foot->prev;
    this->foot->next = NULL;
    this->count--;
    delete foot;
    return last;
}

/**
 * Insert an item to at given index
 *
 */
template<class ElemType>
void list<ElemType>::insert(int index, ElemType elem) {
    node<ElemType>* current = this->head;
    node<ElemType>* new_node = new node<ElemType>(elem);
    while( index != 0 ) {
        current = current->next;
        index--;
    }
    new_node->prev = current->prev;
    new_node->next = current;
    if( current->prev != NULL) {
        current->prev->next = new_node;
    }
    current->prev = new_node;
    this->count++;
}

/**
 * Remove the content of an list
 *
 * @param index Index at which to start changing the list
 * @param howmany The number of elements to remove
 */
template<class ElemType>
void list<ElemType>::remove(int index, int howmany) {
    if (howmany != 1) {
        for (int i = index; i < index + howmany; i++) {
            // note that after last remove, the original INDEX = index + 1
            // now becomes INDEX = index
            this->remove(index, 1);
        }
    } else {
        node<ElemType>* current = this->head;
        while( index != 0 ) {
            current = current->next;
            index--;
        }
        if(current->prev != NULL) {
            current->prev->next = current->next;
        }
        if(current->next != NULL) {
            current->next->prev = current->prev;
        }
        this->count--;
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
    node<ElemType>* current = this->head;
    str += to_string(current->value);
    while(current->next != NULL) {
        current = current->next;
        str += ", ";
        str += to_string(current->value);
    }
    return str;
}

#endif // OOP_LIST_H_
