#include <bits/stdc++.h>
using namespace std;

/*
    Implement only the class below (a queue backed by two stacks).
    void push(int x) -- insert x at the back.
    int  pop()       -- remove and return the front element; -1 if empty.
    int  front()     -- return the front element; -1 if empty.
    int  back()      -- return the last element; -1 if empty.
    bool empty()     -- return true if the queue is empty, else false.
    int  size()      -- return the number of elements.
    All operations must run in O(1).
*/

// Optimal Approach uses 2 Stack
// T.C. -> O(1), S.C.-> O(1).
class MyQueue {
private:
    stack<int> st1;
    stack<int> st2;
    int last = -1;
public:

    MyQueue() {
        st1; st2;
    }

    void push(int x) {
        last = x;
        st1.push(x);
    }

    int pop() {
        int value = front();
        if(value != -1) st2.pop();
        return value;
    }

    int front() {
        if(empty()) return -1;
        if(!st2.empty()) return st2.top();
        while(!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        return st2.top();
    }

    int back() {
        if(empty()) return -1;
        return last;
    }

    bool empty() {
        return st1.empty() && st2.empty();
    }

    int size() {
        return st1.size() + st2.size();
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    MyQueue que;

    string op;

    while (q--)
    {
        cin >> op;

        if (op == "push")
        {
            int x;
            cin >> x;
            que.push(x);
            cout << "null" << '\n';
        }
        else if (op == "pop")
            cout << que.pop() << '\n';
        else if (op == "front")
            cout << que.front() << '\n';
        else if (op == "back")
            cout << que.back() << '\n';
        else if (op == "empty")
            cout << (que.empty() ? "true" : "false") << '\n';
        else // size
            cout << que.size() << '\n';
    }

    return 0;
}
