#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    long long val;
    TreeNode *left, *right;
    TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(const vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoll(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* cur = q.front();
        q.pop();

        if (nodes[i] != "null") {
            cur->left = new TreeNode(stoll(nodes[i]));
            q.push(cur->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != "null") {
            cur->right = new TreeNode(stoll(nodes[i]));
            q.push(cur->right);
        }
        i++;
    }
    return root;
}

// ================= STUDENT FUNCTION =================

// USING DFS
/*
void view(TreeNode* root, int level, vector<long long>& vec) {
    if(root == NULL) {
        return;
    }
    
    if(level == vec.size()) {
        vec.push_back(root->val);
    }
   
    view(root->left, level + 1, vec);
    view(root->right, level + 1, vec);
}

vector<long long> leftView(TreeNode* root) {
    // write your code here
    vector<long long> vec;
    
    view(root, 0, vec);
    
    return vec;
}
*/
// USING BFS
vector<long long> leftView(TreeNode* root) {
    vector<long long> vec;
    
    if(root == NULL) {
        return vec;
    }
    
    queue<TreeNode*> que;
    
    que.push(root);
    
    while(!que.empty()) {
        int queueSize = que.size();
        
        for(int i = 0; i < queueSize; i++) {
            TreeNode* node = que.front();
            que.pop();
            
            if(i == 0) vec.push_back(node->val);
            
            if(node->left != NULL) que.push(node->left);
            if(node->right != NULL) que.push(node->right);
        }
    }
    
    return vec;
}

// ====================================================

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> nodes(n);
    for (int i = 0; i < n; i++) cin >> nodes[i];

    TreeNode* root = buildTree(nodes);

    vector<long long> ans = leftView(root);

    for (int i = 0; i < ans.size(); i++) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << '\n';
}