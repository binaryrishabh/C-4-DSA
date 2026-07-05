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
    Return the node where the cycle begins, or nullptr if there is no cycle.
*/

Node* detectCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL && fast->next !=NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }
    
    if(fast == NULL || fast->next == NULL) return NULL;
    
    slow = head;
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow;
}

// Brute Force Approach Using Sets
// T.C.-> O(N), S.C.-> O(N)
// Node* detectCycle(Node* head) {
//     unordered_set<Node*> set;
    
//     Node* temp = head;
    
//     while(temp != NULL) {
//         if(set.find(temp) != set.end()) return temp;
//         set.insert(temp);
//         temp = temp->next;
//     }
    
//     return NULL;
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

    Node* ans = detectCycle(ll.head);

    int idx = -1;

    for(int i = 0; i < n; i++)
    {
        if(ll.nodes[i] == ans)
        {
            idx = i;
            break;
        }
    }

    cout << idx << '\n';

    return 0;
}
