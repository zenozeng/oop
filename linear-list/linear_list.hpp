#ifndef OOP_LINEAR_LIST_H_
#define OOP_LINEAR_LIST_H_

#include <string>
using namespace std;

template <class ElemType> class linear_list {
public:
    virtual int length(void)=0;
    virtual ElemType nth(int index)=0;
    virtual ElemType pop(void)=0;
    virtual void remove(int index, int howmany = 1)=0;
    virtual void insert(int afterIndex, ElemType elem)=0;
    virtual void push(const ElemType item)=0;
    virtual string join(void)=0;
    virtual ~linear_list(){}; // 析构哪怕纯虚也要有实现的
};

#endif // OOP_LINEAR_LIST_H_
