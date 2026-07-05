#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int v) {
        val = v;
        next = nullptr;
    }
};

class LinkedList {
public:

    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void build(int n) {
        Node* tail = nullptr;

        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;

            Node* node = new Node(x);

            if(!head) {
                head = tail = node;
            }
            else {
                tail->next = node;
                tail = node;
            }
        }
    }
};

/*
    Implement only the function below.
    Reverse the nodes of the list k at a time and return the new head.
    If the number of nodes is not a multiple of k, the leftover nodes at the
    end remain in their original order.
*/

// Best approach using dummy node
// T.C.-> O(N), S.C.-> O(1)
void reverse(Node* leftNode) {
    Node* first = NULL;
    Node* second = leftNode;
    Node* third = leftNode->next;
    
    while(second != NULL) {
        second->next = first;
        first = second;
        second = third;
        if(third != NULL) third = third->next;
    }
}

Node* reverseKGroup(Node* head, int k) {
    Node* dummy = new Node(-1);
    Node* dummyTail = dummy;
    
    Node* currStart = head;
    
    while(currStart != NULL) {
        Node* currEnd = currStart;
        
        for(int i = 1; i < k; i++) {
            currEnd = currEnd->next;
            if(currEnd == NULL) {
                dummyTail->next = currStart;
                head = dummy->next;
                delete dummy;
                return head;
            }
        }
        
        Node* nextStart = currEnd->next;
        currEnd->next = NULL;
        
        reverse(currStart);
        
        dummyTail->next = currEnd;
        dummyTail = currStart;
        
        currStart = nextStart;
    }
    
    head = dummy->next;
    
    delete dummy;
    
    return head;
}


// Bad Code
// T.C.-> O(N), S.C.-> O(1)
// void reverse(Node* leftNode) {
//     Node* first = NULL;
//     Node* second = leftNode;
//     Node* third = leftNode->next;
    
//     while(second != NULL) {
//         second->next = first;
//         first = second;
//         second = third;
//         if(third != NULL) third = third->next;
//     }
// }

// Node* reverseKGroup(Node* head, int k) {
//     if(head == NULL || head->next == NULL || k == 1) return head;
//     Node* temp = head;
    
//     int index = 1;
    
//     Node* left = NULL;
//     Node* leftPoint = NULL;
//     Node* right = NULL;
//     Node* rightNext = NULL;
    
//     while(temp != NULL) {
//         if(index % k == 1) {
//             left = temp;
//         }
//         if(index % k == 0) {
//             right = temp;
//             rightNext = right->next;
//             temp = temp->next;
            
//             right->next = NULL;
            
//             reverse(left);
            
//             if(head == left) head = right;
            
//             if(leftPoint != NULL) {
//                 leftPoint->next = right;
//             }
            
//             leftPoint = left;
//         }
        
//         if(index % k != 0) temp = temp->next;
//         index++;
//     }
    
//     if(leftPoint != NULL) leftPoint->next = rightNext;
    
//     return head;
// }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    LinkedList ll;

    ll.build(n);

    int k;
    cin >> k;

    ll.head = reverseKGroup(ll.head, k);

    Node* cur = ll.head;

    bool first = true;

    while(cur)
    {
        if(!first)
        {
            cout << ' ';
        }

        first = false;

        cout << cur->val;

        cur = cur->next;
    }

    cout << '\n';

    return 0;
}
