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

// Serialize a tree to its level-order (BFS) form: values separated by single
// spaces, "null" for a missing child, trailing "null"s trimmed. Empty -> "".
string serialize(TreeNode* root) {
    if (!root) return "";
    vector<string> out;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* nd = q.front();
        q.pop();
        if (!nd) { out.push_back("null"); continue; }
        out.push_back(to_string(nd->val));
        q.push(nd->left);
        q.push(nd->right);
    }
    while (!out.empty() && out.back() == "null") out.pop_back();
    string res;
    for (size_t i = 0; i < out.size(); i++) {
        if (i) res += ' ';
        res += out[i];
    }
    return res;
}

/*
    Implement only the function below.
    Return the subtree rooted at the node whose value equals val, or null
    if no such node exists.
*/

// Improved Approach uses DFS using an advantage of Binary Search Tree
// T.C.-> O(logN), S.C.-> O(log(Height)
TreeNode* searchBST(TreeNode* root, int val) {
    if(root == NULL) {
        return NULL;
    }
    
    if(root->val == val) {
        return root;
    }
    else if(root->val > val) {
        return searchBST(root->left, val);
    }
    else return searchBST(root->right, val);
}

// Improved Approach uses DFS like a normal binary tree
// T.C.-> O(N), S.C.-> O(height1)
// TreeNode* searchBST(TreeNode* root, int val) {
//     if(root == NULL) {
//         return NULL;
//     }
    
//     if(root->val == val) {
//         return root;
//     }
    
//     TreeNode* node = searchBST(root->left, val);
//     if(node) {
//         return node;
//     }
    
//     return searchBST(root->right, val);
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> nodes(n);
    for (int i = 0; i < n; i++) cin >> nodes[i];

    int val;
    cin >> val;

    TreeNode* root = buildTree(nodes);

    TreeNode* res = searchBST(root, val);

    cout << serialize(res) << '\n';

    return 0;
}
