#include "queue.hpp"
#include <iostream>

int main()
{
    queue<int> q;
    cout << "enque: 1" << endl;
    q.enque(1);
    cout << "enque: 2" << endl;
    q.enque(2);
    cout << "enque: 3" << endl;
    cout << "is_empty? " << (q.is_empty() ? "true" : "false") << endl;
    q.enque(3);
    cout << "len: " << q.length() << endl;
    cout << "deque: =>" << q.deque() << endl;
    cout << "len: " << q.length() << endl;
    cout << "deque: =>" << q.deque() << endl;
    cout << "deque: =>" << q.deque() << endl;
    cout << "len: " << q.length() << endl;
    cout << "is_empty? " << (q.is_empty() ? "true" : "false") << endl;
}
