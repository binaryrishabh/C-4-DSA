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
    Return true iff the two trees are structurally identical and hold the
    same node values.
*/
// Optimal Approach-> USES DFS
// T.C.-> O(N), S.C.->O(Height of Tree)
bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == NULL && q == NULL) {
        return true;
    }
    
    if(p == NULL || q == NULL) {
        return false;
    }
    
    return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n1;
    cin >> n1;
    vector<string> nodes1(n1);
    for (int i = 0; i < n1; i++) cin >> nodes1[i];

    int n2;
    cin >> n2;
    vector<string> nodes2(n2);
    for (int i = 0; i < n2; i++) cin >> nodes2[i];

    TreeNode* p = buildTree(nodes1);
    TreeNode* q = buildTree(nodes2);

    bool ans = isSameTree(p, q);
    cout << (ans ? "true" : "false") << '\n';

    return 0;
}
