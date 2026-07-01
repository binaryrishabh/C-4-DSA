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
    Sort the linked list in ascending order and return the new head.
*/

// T.C. -> O(NlogN), S.C. -> O(1)
// Find the middle Node
Node* middle(Node* head) {
    Node* slow = head;
    Node* fast = head->next;
    
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    Node* mid = slow->next;
    
    // Break the linked list into half
    slow->next = NULL;
    
    return mid;
}

// Merge 
Node* merge(Node* left, Node* right) {
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    
    while(left != NULL && right != NULL) {
        if(left->val < right->val) {
            temp->next = left;
            temp = temp->next;
            left = left->next;
        }
        else {
            temp->next = right;
            temp = temp->next;
            right = right->next;
        }
        temp->next = NULL;
    }
    
    while(left != NULL) {
        temp->next = left;
        temp = temp->next;
        left = left->next;
        temp->next = NULL;
    }
    
    while(right != NULL) {
        temp->next = right;
        temp = temp->next;
        right = right->next;
        temp->next = NULL;
    }
    
    temp = dummy->next;
    
    delete dummy;
    
    return temp;
}

Node* mergeSort(Node* head) {
    if(head == NULL || head -> next == NULL) return head;
    
    Node* left = head;
    
    Node* right = middle(left);
    
    left = mergeSort(left); // left half
    right = mergeSort(right); // right half
    
    return merge(left, right);
}

Node* sortList(Node* head) {
    if(head == NULL || head->next == NULL) return head;
    
    // return head;
    return mergeSort(head);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    LinkedList ll;

    ll.build(n);

    ll.head = sortList(ll.head);

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
