#include <bits/stdc++.h>
using namespace std;

/*
    Implement only the class below.
    void push_front(int x) -- insert x at the front.
    void push_back(int x)  -- insert x at the back.
    int  pop_front()       -- remove and return the front element; -1 if empty.
    int  pop_back()        -- remove and return the back element; -1 if empty.
    int  front()           -- return the front element; -1 if empty.
    int  back()            -- return the back element; -1 if empty.
    bool empty()           -- return true if the deque is empty, else false.
    int  size()            -- return the number of elements.
    All operations must run in O(1).
*/
class Node {
public:
    int val;
    Node* next;
    Node* prev;
    
    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LinkedList {
private:
    Node* head = NULL;
    Node* tail = NULL;
    int size = 0;
    
public:
    void insertFront(int value) {
        Node* newNode = new Node(value);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }
    
    void insertBack(int value) {
        Node* newNode = new Node(value);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
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
            head->prev = NULL;
        }
        
        size--;
        
        del->next = NULL;
        int value = del->val;
        delete del;
        return value;
    }
    
    int removeBack() {
        if(head == NULL) {
            return -1;
        }
        
        Node* del = tail;
        if(head->next == NULL) {
            head = NULL;
            tail = NULL;
        }
        else {
            tail = tail->prev;
            tail->next = NULL;
        }
        
        size--;
        
        del->prev = NULL;
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

class MyDeque {
private:
    LinkedList list;
public:
    MyDeque() {
        list;
    }

    void push_front(int x) {
        list.insertFront(x);
    }

    void push_back(int x) {
        list.insertBack(x);
    }

    int pop_front() {
        return list.removeFront();
    }

    int pop_back() {
        return list.removeBack();
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

    MyDeque dq;

    string op;

    while (q--)
    {
        cin >> op;

        if (op == "push_front")
        {
            int x;
            cin >> x;
            dq.push_front(x);
            cout << "null" << '\n';
        }
        else if (op == "push_back")
        {
            int x;
            cin >> x;
            dq.push_back(x);
            cout << "null" << '\n';
        }
        else if (op == "pop_front")
            cout << dq.pop_front() << '\n';
        else if (op == "pop_back")
            cout << dq.pop_back() << '\n';
        else if (op == "front")
            cout << dq.front() << '\n';
        else if (op == "back")
            cout << dq.back() << '\n';
        else if (op == "empty")
            cout << (dq.empty() ? "true" : "false") << '\n';
        else // size
            cout << dq.size() << '\n';
    }

    return 0;
}
