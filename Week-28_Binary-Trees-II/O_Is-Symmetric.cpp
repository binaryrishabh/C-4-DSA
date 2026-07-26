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
    Return whether the binary tree is a mirror of itself (symmetric).
*/
// Optimal Approach-> USES DFS
// T.C.-> O(N), S.C.->O(Height of Tree)
bool symmetric(TreeNode* leftRoot, TreeNode* rightRoot) {
    if(leftRoot == NULL && rightRoot == NULL) {
         return true;
    }
    if(leftRoot == NULL || rightRoot == NULL) {
        return false;
    }
    
    return leftRoot->val == rightRoot->val && symmetric(leftRoot->left, rightRoot->right) && symmetric(leftRoot->right, rightRoot->left);
}

bool isSymmetric(TreeNode* root) {
    return symmetric(root, root);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> nodes(n);
    for (int i = 0; i < n; i++) cin >> nodes[i];

    TreeNode* root = buildTree(nodes);

    bool ans = isSymmetric(root);

    cout << (ans ? "true" : "false") << '\n';

    return 0;
}
