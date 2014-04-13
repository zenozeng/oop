#ifndef OOP_LINEAR_LIST_H_
#define OOP_LINEAR_LIST_H_

using namespace std;

template <class ElemType>
class linear_list {
private:
    int len;
    int count;
    ElemType* elems;
    void double_capacity(void); // 双倍线性表的长度

public:
    linear_list();
    void push(const ValueType item);
    ElemType pop();
    ElemType nth(int index);
    void splice(int index, int howmany = 1);
}

#endif // OOP_LINEAR_LIST_H_
