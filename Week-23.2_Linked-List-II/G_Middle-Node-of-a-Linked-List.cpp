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
    Implement only the function below.
*/

// NOTE:- If u want that the first node of the middle of the even length LL 
// Just start the fast from the seond node i.e. before starting the loop
// do:- fast = head->next. Rest the code is same slow will start from head 
// move one step and fast will ove two step at a time.


// Optimal; One pass approach
// T.C. => O(N)
Node* findMiddle(Node* head) {
    if(head == NULL || head->next == NULL) return head;
    
    Node* slow = head;
    Node* fast = head;
    
    Node* mid = NULL;
    
    while(fast != NULL && fast->next != NULL) {
        mid = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    if(fast != NULL) mid = slow;
    
    return mid;
}



// Not good:- Two pass approach
// T.C. => O(N + N - K -> 2N)
// Node* findMiddle(Node* head) {
//     if(head == NULL || head->next == NULL) return head;
    
//     Node* temp = head;
//     int size = 0;
//     while(temp != NULL) {
//         size++;
//         temp = temp->next;
//     }
    
//     int mid = (size - 1)/2;
//     temp = head;
//     while(mid > 0) {
//         temp = temp->next;
//         mid--;
//     }
    
//     return temp;
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    LinkedList ll;
    ll.build(n);

    Node* mid = findMiddle(ll.head);
    cout << mid->val << "\n";

    return 0;
}
