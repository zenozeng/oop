#include "stack.hpp"
#include <iostream>
#include <ctime>

int endp;

void benchmark(void) {
    stack<array<int>, int> stack_using_array;
    stack<list<int>, int> stack_using_list;

    clock_t start;
    clock_t end;
    float delta;

    cout << "STACK USING ARRAY BENCHMARK START\n";
    start = clock();
    for(int i = 0; i < 1000 * 10000; i++) {
        stack_using_array.push(i);
    }
    end = clock();
    delta = (end - start) * 1.0 / CLOCKS_PER_SEC;
    cout << "10,000,000 push in " << delta << " seconds." << "\n";

    start = clock();
    for(int i = 0; i < 1000 * 10000; i++) {
        stack_using_array.pop();
    }
    end = clock();
    delta = (end - start) * 1.0 / CLOCKS_PER_SEC;
    cout << "10,000,000 pop in " << delta << " seconds." << "\n";

    cout << endl;

    cout << "STACK USING LIST BENCHMARK START\n";
    start = clock();
    for(int i = 0; i < 1000 * 10000; i++) {
        stack_using_list.push(i);
    }
    end = clock();
    delta = (end - start) * 1.0 / CLOCKS_PER_SEC;
    cout << "10,000,000 push in " << delta << " seconds." << "\n";

    start = clock();
    for(int i = 0; i < 1000 * 10000; i++) {
        stack_using_list.pop();
    }
    end = clock();
    delta = (end - start) * 1.0 / CLOCKS_PER_SEC;
    cout << "10,000,000 pop in " << delta << " seconds." << "\n";


}

int main(void) {

    benchmark();

    return 0;
}
