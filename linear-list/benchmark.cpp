#include "stack.hpp"
#include <iostream>
#include <ctime>

int dotimes = 1000 * 1000;

#define benchmark(name, exp)                                            \
    start = clock();                                                    \
    for(int i = 0; i < dotimes; i++) {                                  \
        exp;                                                            \
    }                                                                   \
    delta = (clock() - start) * 1.0 / CLOCKS_PER_SEC;                   \
    cout << dotimes << " " << name << " in " << delta << " seconds" << endl;

int main(void) {

    stack<array<int>, int> stack_using_array;
    stack<list<int>, int> stack_using_list;

    clock_t start;
    float delta;

    benchmark("push (stack using array)", stack_using_array.push(42));
    benchmark("pop (stack using array)", stack_using_array.pop());
    benchmark("push (stack using list)", stack_using_list.push(42));
    benchmark("pop (stack using list)", stack_using_list.pop());

    return 0;
}
