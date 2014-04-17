#include "stack.hpp"
#include <iostream>
#include <ctime>

int main(void) {

    stack<array<int>, int> stack_using_array;
    stack<list<int>, int> stack_using_list;

    time_t start;
    time_t end;

    cout << "BENCHMARK START\n";
    time(&start);
    for(int i = 0; i < 100000; i++) {
        stack_using_array.push(i);
    }
    time(&end);
    cout << "BENCHMARK END\n";
    cout << difftime(start, end);

    return 0;
}
