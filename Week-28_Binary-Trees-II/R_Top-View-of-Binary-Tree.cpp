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
    Return the top view of the binary tree (left to right).
*/

// Optimal Approach-> USES DFS
// T.C.-> O(NlogN), S.C.-> O(N)

vector<int> topView(TreeNode* root) {
    unordered_map<int, int> map;
    
    queue<pair<TreeNode*, int>> que;
    
    que.push({root, 0});
    
    int start = INT_MAX, end = INT_MIN;
    
    while(!que.empty()) {
        pair<TreeNode*, int> point = que.front();
        que.pop();
        
        TreeNode* node = point.first;
        int col = point.second;
        
        if(map.find(col) == map.end()) {
            map[col] = node->val;
        }
        
        start = min(start, col);
        end = max(end, col);
        
        if(node->left) que.push({node->left, col - 1});
        if(node->right) que.push({node->right, col + 1});
    }
    
    vector<int> vec;
    
    for(int i = start; i <= end; i++) {
        vec.push_back(map[i]);
    }
    
    return vec;
}



// Optimal Approach-> USES DFS
// T.C.-> O(NlogN), S.C.-> O(N)
/*
struct node {
    int val;
    int row;
};

void dfs(TreeNode* root, int row, int col, int& start, int& end, unordered_map<int, node>& map) {
    if(root == NULL) {
        return;
    }
    
    start = min(start, col);
    end = max(end, col);
    
    if(map.find(col) == map.end()) {
        map[col] = {root->val, row};
    }
    else if(map[col].row > row) {
        map[col].val = root->val;
        map[col].row = row;
    }
    
    dfs(root->left, row + 1, col - 1, start, end, map);
    dfs(root->right, row + 1, col + 1, start, end, map);
}

vector<int> topView(TreeNode* root) {
    unordered_map<int, node> map;
    
    int start = INT_MAX, end = INT_MIN;
    
    dfs(root, 0, 0, start, end, map);

    vector<int> vec;
    
    for(int i = start; i <= end; i++) {
        vec.push_back(map[i].val);
    }
    
    return vec;
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

    vector<int> ans = topView(root);

    for (int i = 0; i < (int)ans.size(); i++) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << '\n';

    return 0;
}
