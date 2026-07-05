#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int v)
    {
        val = v;
        next = nullptr;
    }
};

class LinkedList {
public:

    Node* head;
    Node* tail;
    vector<Node*> nodes;

    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void build(int n)
    {
        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            Node* node = new Node(x);

            nodes.push_back(node);

            if(!head)
            {
                head = tail = node;
            }
            else
            {
                tail->next = node;
                tail = node;
            }
        }
    }
};

/*
    Implement only the function below.
    Return true if the linked list has a cycle, otherwise false.
*/


// Optimal
// T.C.-> O(N); S.C.-> O(1)
bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head->next;
        
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    
    return false;
}

// Improved-Hacky
/// T.C.-> O(N); S.C.-> O(1)
// bool hasCycle(Node* head) {
//     const int VISITED = 1e8;
    
//     Node* temp = head;
//     while(temp != NULL) {
//         if(temp->val == VISITED) return true;
//         temp->val = VISITED;
//         temp = temp->next;
//     }
    
//     return false;
// }


// Brute Force
/// T.C.-> O(N); S.C.-> O(N)
// bool hasCycle(Node* head) {
//     set<Node*> set;
    
//     Node* temp = head;
//     while(temp != NULL) {
//         if(set.find(temp) != set.end()) return true;
//         set.insert(temp);
//         temp = temp->next;
//     }
    
//     return false;
// }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    LinkedList ll;

    ll.build(n);

    int pos;
    cin >> pos;

    if(pos != -1)
        ll.tail->next = ll.nodes[pos];

    cout << (hasCycle(ll.head) ? "true" : "false") << '\n';

    return 0;
}
