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
    Return true if the linked list is a palindrome, otherwise false.
*/

// T.C.-> O(N), S.C.-> O(1)
Node* middle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    fast = NULL;
    delete fast;
    
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
    
    delete second;
    delete third;
    
    return first;
}

bool isPalindrome(Node* head) {
    if(head == NULL || head == NULL) {
        return true;
    }
    
    Node* mid = middle(head);
    
    Node* left = head;
    Node* leftTemp = left;
    
    Node* right = reverse(mid);
    Node* rightTemp = right;
    
    bool found = true;
    while(leftTemp != NULL && rightTemp != NULL) {
        if(leftTemp->val != rightTemp->val) {
            found = false;
            break;
        }
        leftTemp = leftTemp->next;
        rightTemp = rightTemp->next;
    }
    
    reverse(right);
    
    left = NULL; right = NULL; leftTemp = NULL; rightTemp = NULL, mid = NULL;
    delete left, right, leftTemp, rightTemp, mid;
    
    return found;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    LinkedList ll;

    ll.build(n);

    cout << (isPalindrome(ll.head) ? "true" : "false") << '\n';

    return 0;
}