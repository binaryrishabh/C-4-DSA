#include <bits/stdc++.h>
using namespace std;

/*
    Implement only the class below, using a singly linked list.
    void push(int x) -- insert x onto the top of the stack.
    int  pop()       -- remove and return the top element; return -1 if empty.
    int  top()       -- return the top element; return -1 if empty.
    bool empty()     -- return true if the stack is empty, else false.
    int  size()      -- return the number of elements in the stack.
    Every operation must run in O(1) time.
*/

class Node {
public:
    Node* next;
    int val;
    
    Node(int val) {
        this->val = val;
    }
};

class MyStack {
    Node* head;
    int length;
public:
    
    MyStack() {
        head = NULL;
        length = 0;
    }

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
        length++;
    }

    int pop() {
        if(head != NULL) {
            Node* del = head;
            head = head->next;
            length--;
            return del->val;
        }
        
        return -1;
    }

    int top() {
        if(head != NULL) {
            return head->val;
        }
        return -1;
    }

    bool empty() {
        return head == NULL;
    }

    int size() {
        return length;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    MyStack st;

    string op;

    while (q--)
    {
        cin >> op;

        if (op == "push")
        {
            int x;
            cin >> x;
            st.push(x);
            cout << "null" << '\n';
        }
        else if (op == "pop")
        {
            cout << st.pop() << '\n';
        }
        else if (op == "top")
        {
            cout << st.top() << '\n';
        }
        else if (op == "empty")
        {
            cout << (st.empty() ? "true" : "false") << '\n';
        }
        else // size
        {
            cout << st.size() << '\n';
        }
    }

    return 0;
}
