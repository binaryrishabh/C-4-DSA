#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void subsequence(int index, int size, int sum, int k, int arr[], vector<int> vec, vector<vector<int>>& ans) {
	if(index == size) {
		if(sum == k) ans.push_back(vec);
		return;
	}
	
	subsequence(index + 1, size, sum, k, arr, vec, ans);
	
	
	vec.push_back(arr[index]);
	subsequence(index + 1, size, sum + arr[index], k, arr, vec, ans);
	vec.pop_back();
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size, k;
	cin >> size >> k;
	
	int arr[size];
	
	for(int i = 0; i < size; i++) {
		int val;
		cin >> val;
		
		arr[i] = val;
	}
	
	vector<int> vec;
	vector<vector<int>> ans;
	subsequence(0, size, 0, k, arr, vec, ans);
	
	cout << ans.size() << endl;
	for(vector<int> sub : ans) {
		for(const auto& val : sub) {
			cout << val << " ";
		}
		cout << endl;
	}
}