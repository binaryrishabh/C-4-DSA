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

// Optimal; One pass approach
// T.C. => O(N)
Node* kthFromEnd(Node* head, int k) {
    Node* slow = head;
    Node* fast = head;
        
    // First move fast pointer till k steps ahead.
    while(k > 0) {
        // If kth node doesn't exist i.e. value of k is greater than the length of complete LL.
        if(fast == NULL) return NULL;
        fast = fast->next;
        k--;
    }
    
    // Now move both fast and slow with one step at a time
    // while maintaining k-step distance between them.
    while(fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow;
}


// Not good:- Two pass approach
// T.C. => O(N + N - K -> 2N)
// Node* kthFromEnd(Node* head, int k) {
//     Node* temp = head;
    
//     int size = 0;
//     while(temp != NULL) {
//         temp = temp->next;
//         size++;
//     }
    
//     int end = size - k;
    
//     temp = head;
//     while(end > 0) {
//         temp = temp->next;
//         end--;
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

    int k;
    cin >> k;

    Node* ans = kthFromEnd(ll.head, k);
    cout << ans->val << "\n";

    return 0;
}
