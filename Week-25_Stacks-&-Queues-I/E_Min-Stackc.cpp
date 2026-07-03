#include <bits/stdc++.h>
using namespace std;

/*
    Implement only the class below.
*/

class Node {
public:
    int val;
    int min;
    Node* next;
    
    Node(int val, int min) {
        this->val = val;
        this->min = min;
    }
};

class MinStack {
private:
    Node* head;
public:
    MinStack() {
        // implement
        head = NULL;
    }

    void push(long long x) {
        // implement
        int min_val = x;
        
        if(head != NULL) {
            min_val = min(min_val, head->min);
        }
        
        Node* newNode = new Node(x, min_val);
        newNode->next = head;
        head = newNode;
    }

    void pop() {
        // implement
        if(head == NULL) return;
        
        Node* del = head;
        head = head->next;
        delete del;
    }

    long long top() {
        // implement
        if(head == NULL) return -1;
        
        return head->val;
    }

    long long getMin() {
        // implement
        if(head == NULL) return -1;
        
        return head->min;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    MinStack st;

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            long long x;
            cin >> x;
            st.push(x);
        } else if (type == 2) {
            st.pop();
        } else if (type == 3) {
            cout << st.top() << "\n";
        } else {
            cout << st.getMin() << "\n";
        }
    }

    return 0;
}