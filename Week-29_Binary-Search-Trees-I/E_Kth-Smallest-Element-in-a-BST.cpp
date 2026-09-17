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
    Return the k-th smallest value (1-indexed) in the BST.
*/

// Approach -> Checking BST while traversing in inorder way
// T.C.-> O(k), S.C.-> O(height of tree)
void inorderTraversal(TreeNode* root, int& val, int& k) {
    if(root == NULL) {
        return;
    }

    inorderTraversal(root->left, val, k);

    k--;
    if(k == 0) {
        val = root->val;
        return;
    }
    
    inorderTraversal(root->right, val, k);
}

int kthSmallest(TreeNode* root, int k) {
    int val;

    inorderTraversal(root, val, k);

    return val;
}


// Approach -> Using vector i.e. extra space to store node values
// T.C.-> O(k), S.C.-> O(N)
/*
void inorderTraversal(TreeNode* root, vector<int>& vec, int k) {
    if(root == NULL) {
        return;
    }
    
    inorderTraversal(root->left, vec, k);
    vec.push_back(root->val);
    if(vec.size() >= k) {
        return;
    }
    inorderTraversal(root->right, vec, k);
}

int kthSmallest(TreeNode* root, int k) {
    vector<int> vec;
    
    inorderTraversal(root, vec, k);
    
    return vec[k - 1];
}
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> nodes(n);
    for (int i = 0; i < n; i++) cin >> nodes[i];

    int k;
    cin >> k;

    TreeNode* root = buildTree(nodes);

    cout << kthSmallest(root, k) << '\n';

    return 0;
}
