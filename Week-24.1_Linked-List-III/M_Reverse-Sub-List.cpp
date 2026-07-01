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
    Reverse the nodes from position left to right (1-indexed, inclusive)
    and return the head of the modified list.
*/

Node* reverseBetween(Node* head, int left, int right) {
    Node* leftPrev = NULL;
    Node* second = head;
    
    int reverse = right - left + 1;
    
    while(left > 1) {
        leftPrev = second;
        second = second->next;
        left--;
    }
    
    Node* leftNode = second;
    
    Node* first = NULL;
    Node* third = second->next;
    
    while(reverse > 0) {
        second->next = first;
        first = second;
        second = third;
        if(third != NULL) third = third->next;
        reverse--;
    }
    
    if(leftPrev != NULL) {
        leftPrev->next = first;
    }
    else {
        head = first;
    }
    leftNode->next = second;
    
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

    int left, right;
    cin >> left >> right;

    ll.head = reverseBetween(ll.head, left, right);

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
