#include "linear_list.h"
#include <iostream>
#include <cassert>
#include <cstring>

int main()
{
    linear_list<int> arr;
    arr.push(1);
    arr.push(2);
    arr.push(3);
    cout << "\n=== push ===\n";
    cout << arr.join();
    cout << "\n=== nth ===\n";
    cout << arr.nth(1);
    cout << "\n=== pop ===\n";
    cout << arr.pop();
    cout << "\n";
    cout << arr.join();
    cout << "\n=== splice ===\n";
    arr.push(3);
    arr.push(4);
    arr.push(5);
    cout << arr.join();
    cout << "\n";
    arr.splice(2, 2);
    cout << arr.join();
    cout << "\n=== length ===\n";
    cout << arr.length();
    return 0;
}
