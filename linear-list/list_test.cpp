#include "list.hpp"
#include <iostream>
#include <cstring>

int main()
{
    list<int> li;
    li.push(1);
    li.push(2);
    li.push(3);
    cout << "\n=== push ===\n";
    cout << li.join();
    cout << "\n";
    cout << li.length();
    cout << "\n=== nth ===\n";
    cout << li.nth(1);
    cout << "\n=== pop ===\n";
    cout << li.pop();
    cout << "\n";
    cout << li.join();
    cout << "\n=== remove ===\n";
    li.push(3);
    li.push(4);
    li.push(5);
    cout << li.join();
    cout << "\n";
    li.remove(2, 2);
    cout << li.join();
    cout << "\n=== length ===\n";
    cout << li.join();
    cout << "\n";
    cout << li.length();
    cout << "\n=== insert ===\n";
    li.push(7);
    li.push(8);
    li.push(9);
    cout << li.join();
    cout << "\n";
    li.insert(2, 10);
    cout << li.join();
    return 0;
}
