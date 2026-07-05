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

    LinkedList()
    {
        head = nullptr;
    }

    void build(int n)
    {
        Node* tail = nullptr;

        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            Node* node = new Node(x);

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
    Delete the middle node and return the head of the modified list.
    The middle node is the floor(n / 2)-th node (0-indexed).
*/

// Optimal:- 
// T.C. => O(N); S.C. => O(1)
Node* deleteMiddle(Node* head) {
    if(head == NULL || head->next == NULL) return NULL;

    Node* mid = NULL;
    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL && fast->next != NULL) {
        mid = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    mid->next = mid->next->next;
    slow = NULL;
    fast = NULL;
    delete slow;
    delete fast;
    
    return head;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    LinkedList ll;

    ll.build(n);

    ll.head = deleteMiddle(ll.head);

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
