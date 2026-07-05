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
    Reorder the list in place from
        L0 -> L1 -> ... -> Ln-1
    to
        L0 -> Ln-1 -> L1 -> Ln-2 -> L2 -> ...
    Do not return anything; modify the list in place.
*/

Node* middle(Node* head) {
    Node* mid = NULL;
    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL && fast->next != NULL) {
        mid = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    if(mid != NULL) mid->next = NULL;
    
    return slow;
}

Node* reverse(Node* mid) {
    Node* first = NULL;
    Node* second = mid;
    Node* third = mid->next;
    
    while(second != NULL) {
        second->next = first;
        first = second;
        second = third;
        if(third != NULL) third = third->next;
    }
    
    return first;
}

void reorderList(Node* head) {
    if(head == NULL || head->next == NULL) return;
    
    Node* dummy = new Node(-1);
    
    Node* temp = dummy;
    
    Node* mid = middle(head);
    
    Node* first = head;
    Node* second = reverse(mid);
    
    while(first != NULL && second != NULL) {
        temp->next = first;
        temp = temp->next;
        first = first->next;
        temp->next = NULL;
        
        temp->next = second;
        temp = temp->next;
        second = second->next;
        temp->next = NULL;
    }
    
    temp->next = second;
    
    head = dummy->next;
    
    delete dummy;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    LinkedList ll;

    ll.build(n);

    reorderList(ll.head);

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