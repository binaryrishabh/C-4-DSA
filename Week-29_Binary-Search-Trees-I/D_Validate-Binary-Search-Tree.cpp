#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(const vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < (int)nodes.size()) {
        TreeNode* cur = q.front();
        q.pop();

        if (nodes[i] != "null") {
            cur->left = new TreeNode(stoi(nodes[i]));
            q.push(cur->left);
        }
        i++;

        if (i < (int)nodes.size() && nodes[i] != "null") {
            cur->right = new TreeNode(stoi(nodes[i]));
            q.push(cur->right);
        }
        i++;
    }
    return root;
}

/*
    Implement only the function below.
    Return whether the binary tree is a valid Binary Search Tree.
*/
// Approach -> Checking BST while traversing in inorder way
// T.C.-> O(N), S.C.-> O(height of tree)
void isValid(TreeNode* root, long long& prev, bool& isBST) {
    if(root == NULL) {
        return;
    }
    
    isValid(root->left, prev, isBST);
    
    if(root->val <= prev) {
        isBST = false;
        return;
    }
    
    prev = root->val;
    
    isValid(root->right, prev, isBST);
}

bool isValidBST(TreeNode*root) {
    bool isBST = true;
    long long prev = LLONG_MIN;
    isValid(root, prev, isBST);
    return isBST;
}

// Approach -> Using vector i.e. extra space to store node values
// T.C.-> O(N), S.C.-> O(N)
/*
void inorderTraversal(TreeNode* root, vector<int>& vec) {
    if(root == NULL) {
        return;
    }
    
    inorderTraversal(root->left, vec);
    vec.push_back(root->val);
    inorderTraversal(root->right, vec);
}
bool isValidBST(TreeNode* root) {
    vector<int> vec;
    
    inorderTraversal(root, vec);
    
    for(int i = 1; i < vec.size(); i++) {
        if(vec[i] <= vec[i - 1]) {
            return false;
        }
    }
    
    return true;
}
*/


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> nodes(n);
    for (int i = 0; i < n; i++) cin >> nodes[i];

    TreeNode* root = buildTree(nodes);

    bool ans = isValidBST(root);

    cout << (ans ? "true" : "false") << '\n';

    return 0;
}