#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void build(int n) {
        Node* tail = nullptr;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            Node* node = new Node(x);
            if (!head) head = tail = node;
            else tail->next = node, tail = node;
        }
    }

    void print() {
        bool first = true;
        Node* cur = head;
        while (cur) {
            if (!first) cout << ' ';
            cout << cur->val;
            first = false;
            cur = cur->next;
        }
        cout << "\n";
    }

    ~LinkedList() {
        Node* cur = head;
        while (cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }
};

/*
    Implement only the class below.
*/

// We have both head & tail pointers. 
// So adding at tail takes O(1)

class MyLinkedList {
private:
    Node* headNode;
    Node* tailNode;
    int size;
    
    // T.C.-> O(K)
    Node* getKthNode(int index) {
        Node* temp = headNode;
        
        while(index > 1) {
            temp = temp->next;
            index--;
        }
        
        return temp;
    }
public:
    MyLinkedList(Node* head) {
        // implement
        headNode = head;
        size = 0;
        
        Node* temp = head;
        
        while(temp != NULL) {
            tailNode = temp;
            temp = temp->next;
            size++;
        }
    }
    
    // T.C.-> O(K)
    int get(int index) {
        // implement
        if(index < 0 || index >= size) return -1;
            
        Node* node = getKthNode(index + 1);
        
        return node->val;
    }
    
    // T.C.-> O(1)
    void addAtHead(int val) {
        // implement
        Node* newNode = new Node(val);
        newNode->next = headNode;
        // updating tailNode if list is empty.
        if(size == 0) {
            tailNode = newNode;
        }
        headNode = newNode;
        size++;
    }
    
    // T.C.-> O(1)
    void addAtTail(int val) {
        // implement
        if(size == 0) {
            addAtHead(val);
            return;
        }
        
        Node* newNode = new Node(val);
        
        tailNode->next = newNode;
        tailNode = newNode;
        
        size++;
    }

    // T.C.-> O(K)
    void addAtIndex(int index, int val) {
        // implement
        if(index > size) return;
        
        if(index <= 0) {
            addAtHead(val);
            return;
        }
        
        if(index == size) {
            addAtTail(val);
            return;
        }
        
        Node* newNode = new Node(val);
        
        Node* prev = getKthNode(index);
        
        newNode->next = prev->next;
        prev->next = newNode;
        
        size++;
    }

    // T.C.-> O(K)
    void deleteAtIndex(int index) {
        // implement
        if(index < 0 || index >= size) {
            return;
        }
        
        if(index == 0) {
            Node* del = headNode;
            headNode = headNode->next;
            delete del;
            size--;
            return;
        }
        
        Node* temp = headNode;
        
        Node* prev = getKthNode(index);
        
        Node* del = prev->next;
        
        if(index == size - 1) {
            tailNode = prev;
        }
        
        prev->next = prev->next->next;
        
        delete del;
        size--;
    }

    Node* getHead() {
        // implement
        return headNode;
    }
};


// We only have head pointer.
// So adding and removing at tail takes O(N)

// class MyLinkedList {
// private:
//     Node* headNode;
//     int size;
    
//     // T.C.-> O(K)
//     Node* getKthNode(int index) {
//         Node* temp = headNode;
        
//         while(index > 1) {
//             temp = temp->next;
//             index--;
//         }
        
//         return temp;
//     }
// public:
//     MyLinkedList(Node* head) {
//         // implement
//         headNode = head;
//         size = 0;
        
//         Node* temp = head;
        
//         while(temp != NULL) {
//             temp = temp->next;
//             size++;
//         }
//     }
    
//     // T.C.-> O(K)
//     int get(int index) {
//         // implement
//         if(index < 0 || index >= size) return -1;
            
//         Node* node = getKthNode(index + 1);
        
//         return node->val;
//     }
    
//     // T.C.-> O(1)
//     void addAtHead(int val) {
//         // implement
//         Node* newNode = new Node(val);
//         newNode->next = headNode;
//         headNode = newNode;
//         size++;
//     }
    
//     // T.C.-> O(N)
//     void addAtTail(int val) {
//         // implement
//         addAtIndex(size, val);
//     }

//     // T.C.-> O(K)
//     void addAtIndex(int index, int val) {
//         // implement
//         if(index > size) return;
        
//         if(index <= 0) {
//             addAtHead(val);
//             return;
//         }
        
//         Node* newNode = new Node(val);
        
//         Node* prev = getKthNode(index);
        
//         newNode->next = prev->next;
//         prev->next = newNode;
        
//         size++;
//     }

//     // T.C.-> O(K)
//     void deleteAtIndex(int index) {
//         // implement
//         if(index < 0 || index >= size) {
//             return;
//         }
        
//         if(index == 0) {
//             Node* del = headNode;
//             headNode = headNode->next;
//             delete del;
//             size--;
//             return;
//         }
        
//         Node* temp = headNode;
        
//         Node* prev = getKthNode(index);
        
//         Node* del = prev->next;
        
//         prev->next = prev->next->next;
        
//         delete del;
//         size--;
//     }

//     Node* getHead() {
//         // implement
//         return headNode;
//     }
// };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    LinkedList ll;
    ll.build(n);

    MyLinkedList my(ll.head);

    int Q;
    cin >> Q;

    while (Q--) {
        int type;
        cin >> type;
        if (type == 0) {
            int index;
            cin >> index;
            cout << my.get(index) << "\n";
        } else if (type == 1) {
            int val;
            cin >> val;
            my.addAtHead(val);
        } else if (type == 2) {
            int val;
            cin >> val;
            my.addAtTail(val);
        } else if (type == 3) {
            int index, val;
            cin >> index >> val;
            my.addAtIndex(index, val);
        } else {
            int index;
            cin >> index;
            my.deleteAtIndex(index);
        }
    }

    ll.head = my.getHead();
    ll.print();
    return 0;
}