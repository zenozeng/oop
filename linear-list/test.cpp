#include "array.hpp"
#include <iostream>
#include <cassert>
#include <cstring>

int main()
{
    array<int> arr;
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
    cout << "\n=== remove ===\n";
    arr.push(3);
    arr.push(4);
    arr.push(5);
    cout << arr.join();
    cout << "\n";
    arr.remove(2, 2);
    cout << arr.join();
    cout << "\n=== length ===\n";
    cout << arr.length();
    cout << "\n=== insert ===\n";
    arr.push(7);
    arr.push(8);
    arr.push(9);
    arr.insert(2, 10);
    cout << arr.join();
    return 0;
}
