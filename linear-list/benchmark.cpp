#include "stack.hpp"
#include <iostream>
#include <ctime>

int main(void) {

    stack<array<int>, int> stack_using_array;
    stack<list<int>, int> stack_using_list;

    time_t start;
    time_t end;

    cout << "STACK USING ARRAY BENCHMARK START\n";
    time(&start);
    for(int i = 0; i < 10000 * 10000; i++) {
        stack_using_array.push(i);
    }
    time(&end);
    cout << "100,000,000 push in " << difftime(end, start) << " seconds." << "\n";

    time(&start);
    for(int i = 0; i < 10000 * 10000; i++) {
        stack_using_array.pop();
    }
    time(&end);
    cout << "100,000,000 pop in " << difftime(end, start) << " seconds." << "\n";


    cout << "STACK USING LIST BENCHMARK START\n";
    time(&start);
    for(int i = 0; i < 10000 * 10000; i++) {
        stack_using_list.push(i);
    }
    time(&end);
    cout << "100,000,000 push in " << difftime(end, start) << " seconds." << "\n";

    time(&start);
    for(int i = 0; i < 10000 * 10000; i++) {
        stack_using_list.pop();
    }
    time(&end);
    cout << "100,000,000 pop in " << difftime(end, start) << " seconds." << "\n";

    return 0;
}
