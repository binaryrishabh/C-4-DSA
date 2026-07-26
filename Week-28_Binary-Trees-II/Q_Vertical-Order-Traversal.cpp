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
    Return the vertical order traversal: one list per column, from the
    leftmost column to the rightmost.
*/

// Optimal Approach-> USES BFS
// T.C.-> O(NlogN), S.C.-> O(N)
struct node {
  int val;
  int row; 
  int col;
};

bool comparator(node first, node second) {
    if(first.row != second.row) {
        return first.row < second.row;
    }
    else if(first.col != second.col) {
        return first.col < second.col;
    }
    
    return first.val < second.val;
}

vector<vector<int>> verticalTraversal(TreeNode* root) {
    unordered_map<int, vector<node>> map;
    
    queue<pair<TreeNode*, node>> que;
    
    que.push({root, {root->val, 0, 0}});
    
    int start = 0, end = 0;
    
    while(!que.empty()) {
        pair<TreeNode*, node> point = que.front();
        que.pop();
        
        TreeNode* currNode = point.first;
        node currNodeData = point.second;
        
        int val = currNodeData.val;
        int row = currNodeData.row;
        int col = currNodeData.col;
        
        start = min(start, col);
        end = max(end, col);
        
        map[currNodeData.col].push_back({val, row, col});
        
        if(currNode->left) que.push({currNode->left, {currNode->left->val, row + 1, col - 1}});
        if(currNode->right) que.push({currNode->right, {currNode->right->val, row + 1, col + 1}});
    }
    
    vector<vector<int>> vec;
    
    for(int i = start; i <= end; i++) {
        vector<int> innerVec;
        
        sort(map[i].begin(), map[i].end(), comparator);
        
        for(node point : map[i]) {
            innerVec.push_back(point.val);
        }
        vec.push_back(innerVec);
    }
    
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

    vector<vector<int>> ans = verticalTraversal(root);

    for (auto& col : ans) {
        for (int i = 0; i < (int)col.size(); i++) {
            if (i) cout << " ";
            cout << col[i];
        }
        cout << '\n';
    }

    return 0;
}