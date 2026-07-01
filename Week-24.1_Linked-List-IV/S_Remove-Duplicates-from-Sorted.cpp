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
    The list is sorted in non-decreasing order. Delete all duplicates so that
    each value appears only once, and return the head of the modified list.
*/

// Fastest Approach.
Node* deleteDuplicates(Node* head) {
    Node* temp = head;
    
    while(temp != NULL && temp->next != NULL) {
        if(temp->val == temp->next->val) {
            temp->next = temp->next->next;
        }
        else {
            temp = temp->next;
        }
    }
    
    return head;
}

// Approach uses dummy nodes.
// Node* deleteDuplicates(Node* head) {    
    // Node* dummy = new Node(-1);
    
    // Node* temp = dummy;
    
    // Node* ptr = head;
    
    // while(ptr != NULL && ptr->next != NULL) {
    //     if(ptr->val != ptr->next->val) {
    //         temp->next = ptr;
    //         temp = temp->next;
    //         ptr = ptr->next;
    //         temp->next = NULL;
    //     }
    //     else {
    //         ptr = ptr->next;
    //     }
    // }
    
    // temp->next = ptr;
    
    // head = dummy->next;
    
    // temp = NULL;
    // ptr = NULL;
    
    // delete temp;
    // delete ptr;
    // delete dummy;
    
    // return head;
// }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    LinkedList ll;

    ll.build(n);

    ll.head = deleteDuplicates(ll.head);

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
