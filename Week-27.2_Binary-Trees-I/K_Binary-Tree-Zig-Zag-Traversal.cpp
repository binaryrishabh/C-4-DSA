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
vector<vector<long long>> zigzagLevelOrder(TreeNode* root) {
    // write your code here
    vector<vector<long long>> vec;
    
    if(root == NULL) {
        return vec;
    }
    
    queue<TreeNode*> que;
    
    que.push(root);
    
    int level = 0;
    
    while(!que.empty()) {
        int queueSize = que.size();
        
        vector<long long> innerVec;
        
        for(int i = 0; i < queueSize; i++) {
            TreeNode* node = que.front();
            que.pop();
            
            innerVec.push_back(node->val);
            
            if(node->left != NULL) que.push(node->left); 
            if(node->right != NULL) que.push(node->right); 
        }
        
        if((level & 1) == 1) {
            reverse(innerVec.begin(), innerVec.end());
        }
            
        vec.push_back(innerVec);
        
        level++;
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

    vector<vector<long long>> ans = zigzagLevelOrder(root);

    for (auto &level : ans) {
        for (int i = 0; i < level.size(); i++) {
            if (i) cout << " ";
            cout << level[i];
        }
        cout << '\n';
    }
}