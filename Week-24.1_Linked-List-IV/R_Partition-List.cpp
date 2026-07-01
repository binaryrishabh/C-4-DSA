#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    
    Node() {
        next = nullptr;
    }

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
    Partition the list so that every node with value < x comes before every
    node with value >= x, preserving the original relative order within each
    of the two partitions. Return the head of the partitioned list.
*/

Node* partition(Node* head, int x) {
    Node* dummy1 = new Node(-1);
    Node* dummy2 = new Node(-1);
    
    Node* temp1 = dummy1;
    Node* temp2 = dummy2;
    
    Node* temp = head;
    
    while(temp != NULL) {
        if(temp->val < x) {
            temp1->next = temp;
            temp1 = temp1->next;
            temp = temp->next;
            temp1->next = NULL;
        }
        else {
            temp2->next = temp;
            temp2 = temp2->next;
            temp = temp->next;
            temp2->next = NULL;
        }
    }
    
    temp1->next = dummy2->next;
    
    temp1 = NULL;
    temp2 = NULL;
    
    head = dummy1->next;
    
    delete dummy1;
    delete dummy2;
    delete temp1;
    delete temp2;
    
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

    int x;
    cin >> x;

    ll.head = partition(ll.head, x);

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
