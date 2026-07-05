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
    Merge two sorted (non-decreasing) lists into one sorted list and return
    the head of the merged list. Either list may be empty (nullptr).
*/

// Optimal:- 
// T.C. => O(N + M); S.C. => O(1)
Node* mergeTwoLists(Node* l1, Node* l2) {
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    
    Node* temp1 = l1;
    Node* temp2 = l2;
    
    while(temp1 != NULL && temp2 != NULL) {
        if(temp1->val < temp2->val) {
            temp->next = temp1;
            temp1 = temp1->next;
        }
        else {
            temp->next = temp2;
            temp2 = temp2->next;
        }
        temp = temp->next;
        temp->next = NULL;
    }
    
    while(temp1 != NULL) {
        temp->next = temp1;
        temp = temp->next;
        temp1 = temp1->next;
        temp->next = NULL;
    }
    
    while(temp2 != NULL) {
        temp->next = temp2;
        temp = temp->next;
        temp2 = temp2->next;
        temp->next = NULL;
    }
    
    Node* head = dummy->next;
    
    temp = NULL;
    
    delete temp;
    delete temp1;
    delete temp2;
    delete dummy;
    
    return head;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n1;
    cin >> n1;

    LinkedList a;
    a.build(n1);

    int n2;
    cin >> n2;

    LinkedList b;
    b.build(n2);

    Node* head = mergeTwoLists(a.head, b.head);

    Node* cur = head;

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
