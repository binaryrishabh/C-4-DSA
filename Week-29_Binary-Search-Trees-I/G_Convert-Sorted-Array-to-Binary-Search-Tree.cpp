#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

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
    Given `nums` sorted in strictly increasing order, build a height-balanced
    BST using the mid = (lo + hi) / 2 (left-of-middle) root convention and
    return its root.
*/
// T.C.-> O(N), S.C.-> O(height of tree)
TreeNode* constructTree(vector<int>& nums, int left, int right) {
	if(left > right) {
		return NULL;
	}
	
	int mid = left + (right - left) / 2;
	
	TreeNode* root = new TreeNode(nums[mid]);
	
	root->left = constructTree(nums, left, mid - 1);
	root->right = constructTree(nums, mid + 1, right);
	
	return root;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
	return constructTree(nums, 0, nums.size() - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    TreeNode* root = sortedArrayToBST(nums);

    cout << serialize(root) << '\n';
    return 0;
}
