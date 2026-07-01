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

    Node* getTail() {
        Node* cur = head;
        if (!cur) return nullptr;
        while (cur->next) cur = cur->next;
        return cur;
    }

    Node* getNodeAt(int idx) { // 0-indexed
        Node* cur = head;
        while (cur && idx--) cur = cur->next;
        return cur;
    }

    ~LinkedList() {
    }
};

/*
    Implement only the function below.
*/

// Optimal:- Two pass approach
// T.C. => O(2*(N + M)); S.C. => O(1)
Node* getIntersectionNode(Node* headA, Node* headB) {
    Node* tempA = headA;
    Node* tempB = headB;
    
    int count1 = 0, count2 = 0;
    
    while(tempA != tempB) {
        // Why to move next at startig of the LL not at the end.
        // When tempA becomes NULL, I reset it to headB, but in the 
        // same iteration I immediately execute tempA = tempA->next, 
        // so headB is skipped. Similarly, when tempB becomes NULL,
        // I reset it to headA and immediately move it to headA->next,
        // skipping headA. Therefore, if the intersection starts at
        // headB (or the reset node), that node is never compared,
        // and the pointers end up meeting one node later. 
        tempA = tempA->next;
        tempB = tempB->next;
        
        if(count1 > 1 || count2 > 1) return NULL;
        
        if(tempA == NULL) {
            count1++;
            tempA = headB;
        }
        if(tempB == NULL) {
            count2++;
            tempB = headA;
        }
    }
    
    return tempA;
}

// Improved:- Three pass approach
// T.C. => O(N + M + max(N + M)); S.C. => O(1)
// Node* getIntersectionNode(Node* headA, Node* headB) {
//     Node* tempA = headA;
//     Node* tempB = headB;
    
//     int length1 = 0, length2 = 0;
    
//     // find length of headA    
//     while(tempA != NULL) {
//         length1++;
//         tempA = tempA->next;
//     }
    
//     // find length of headB
//     while(tempB != NULL) {
//         length2++;
//         tempB = tempB->next;
//     }
    
//     // Diff btw both lists size
//     int diff = abs(length1 - length2);
    
//     // Move the greater list diff distance ahead
//     tempA = headA;
//     tempB = headB;
//     if(length1 > length2) {
//         while(diff > 0) {
//             tempA = tempA->next;
//             diff--;
//         }
//     }
    
//     if(length1 < length2) {
//         while(diff > 0) {
//             tempB = tempB->next;
//             diff--;
//         }
//     }
    
//     // Now find the intersection as both list will start from same 
//     // distance from the end and intersection. If there is one intersection.
//     while(tempA != NULL && tempB != NULL) {
//         if(tempA == tempB) return tempA;
//         tempA = tempA->next;
//         tempB = tempB->next;
//     }
    
//     return NULL;
// }


// Not good:- Two pass approach
// T.C. => O(N + M); S.C. => O(N)
// Node* getIntersectionNode(Node* headA, Node* headB) {
//     // As all addresses are unique we can use the set.
//     set<Node*> set;
    
//     // Insert all the node addresses of list 1 inside a set.
//     Node* tempA = headA;
//     while(tempA != NULL) {
//         set.insert(tempA);
//         tempA = tempA->next;
//     }
    
//     // Now check that if any address of list2 present in set. If yes return 
//     // that node.
//     Node* tempB = headB;
//     while(tempB != NULL) {
//         if(set.find(tempB) != set.end()) {
//             return tempB;
//         }
//         tempB = tempB->next;
//     }
    
//     return tempB;
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int nA, nB, common;
    cin >> nA >> nB >> common;

    LinkedList A, B, C;
    A.build(nA - common);
    B.build(nB - common);
    C.build(common);

    Node* commonHead = C.head;

    if (A.getTail()) A.getTail()->next = commonHead;
    else A.head = commonHead;

    if (B.getTail()) B.getTail()->next = commonHead;
    else B.head = commonHead;

    Node* ans = getIntersectionNode(A.head, B.head);

    if (ans == nullptr) cout << -1 << "\n";
    else cout << ans->val << "\n";

    return 0;
}
