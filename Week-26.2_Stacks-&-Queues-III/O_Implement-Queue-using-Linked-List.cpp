#include <bits/stdc++.h>
using namespace std;

/*
    Implement only the class below (a queue backed by a singly linked list).
    void push(int x) -- insert x at the back.
    int  pop()       -- remove and return the front element; -1 if empty.
    int  front()     -- return the front element; -1 if empty.
    int  back()      -- return the last element; -1 if empty.
    bool empty()     -- return true if the queue is empty, else false.
    int  size()      -- return the number of elements.
    All operations must run in O(1).
*/

class Node {
public:
    int val;
    Node* next;
    
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class LinkedList {
private:
    Node* head = NULL;
    Node* tail = NULL;
    int size = 0;
    
public:
    void insertBack(int val) {
        Node* newNode = new Node(val);
        
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    
    int removeFront() {
        if(head == NULL) {
            return -1;
        }
        
        Node* del = head;
        if(head->next == NULL) {
            head = NULL;
            tail = NULL;
        }
        else {
            head = head->next;
        }
        size--;
        
        int value = del->val;
        delete del;
        return value;
    }
    
    int getFront() {
        if(head == NULL) {
            return -1;
        }
        
        return head->val;
    }
    
    int getBack() {
        if(head == NULL) {
            return -1;
        }
        
        return tail->val;
    }
    
    bool empty() {
        return head == NULL;
    }
    
    int getSize() {
        return size;
    }
};

class MyQueue {
private:
    LinkedList list;
public:
    MyQueue() {
        list;
    }

    void push(int x) {
        list.insertBack(x);
        return;
    }

    int pop() {
        return list.removeFront();
    }

    int front() {
        return list.getFront();
    }

    int back() {
        return list.getBack();
    }

    bool empty() {
        return list.empty();
    }

    int size() {
        return list.getSize();
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
