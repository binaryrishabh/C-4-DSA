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
    Return the anti-clockwise boundary traversal of the binary tree
    (root, left boundary, leaves left-to-right, right boundary).
*/

// Optimal Approach-> USES DFS
// T.C.-> O(N), S.C.-> O(h)
void leftDfs(TreeNode* root, vector<int>& vec) {
    if(root == NULL) {
        return;
    }
    
    if(!root->left && !root->right) {
        return;
    }
    
    vec.push_back(root->val);
    
    if(root->left) {
        leftDfs(root->left, vec);
    }
    else {
        leftDfs(root->right, vec);
    }
}

void leafDfs(TreeNode* root, vector<int>& vec) {
    if(root == NULL) {
        return;
    }
    
    if(!root->left && !root->right) {
        vec.push_back(root->val);
    }
    
    leafDfs(root->left, vec);
    leafDfs(root->right, vec);
}

void rightDfs(TreeNode* root, vector<int>& vec) {
    if(root == NULL) {
        return;
    }
    
    if(!root->left && !root->right) {
        return;
    }
    
    if(root->right) {
        rightDfs(root->right, vec);
    }
    else {
        rightDfs(root->left, vec);
    }
    
    vec.push_back(root->val);
}


vector<int> boundary(TreeNode* root) {
    vector<int> vec;
    
    vec.push_back(root->val);
    
    leftDfs(root->left, vec);
    
    if(root->left || root->right) {
        leafDfs(root, vec);
    }
    
    rightDfs(root->right, vec);
    
    return vec;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> nodes(n);
    for (int i = 0; i < n; i++) cin >> nodes[i];

    TreeNode* root = buildTree(nodes);

    vector<int> ans = boundary(root);

    for (int i = 0; i < (int)ans.size(); i++) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << '\n';

    return 0;
}
