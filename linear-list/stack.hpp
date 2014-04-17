#ifndef OOP_STACK_H_
#define OOP_STACK_H_

#include "linear_list.hpp"
#include "array.hpp"
#include "list.hpp"

using namespace std;

template <typename Engine, typename ElemType>
class stack {
private:
    linear_list<ElemType>* instance;
public:
    stack();
    ~stack();
    void push(ElemType elem);
    int length(void);
    ElemType pop(void);
};
    
template <typename Engine, typename ElemType>
stack<Engine, ElemType>::stack() {
    this->instance = new Engine;
}
template <typename Engine, typename ElemType>
stack<Engine, ElemType>::~stack() {
    delete this->instance;
}
template <typename Engine, typename ElemType>
int stack<Engine, ElemType>::length() {
    return this->instance->length();
}
template <typename Engine, typename ElemType>
void stack<Engine, ElemType>::push(ElemType elem) {
    this->instance->push(elem);
}
template <typename Engine, typename ElemType>
ElemType stack<Engine, ElemType>::pop() {
    return this->instance->pop();
}

#endif // OOP_STACK_H_
