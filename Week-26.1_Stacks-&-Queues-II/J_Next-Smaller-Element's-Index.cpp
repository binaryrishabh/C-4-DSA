#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size;
	cin >> size;
	
	vector<int> vec(size, 0);
	
	for(int i = 0; i < size; i++) {
		cin >> vec[i];
	}
	
	stack<int> st;
	vector<int> ans;
	
	for(int i = size - 1; i >= 0; i--) {
		while(!st.empty() && vec[st.top()] >= vec[i]) {
			st.pop();
		}
		
		if(!st.empty()) {
			ans.push_back(st.top());
		}
		else {
			ans.push_back(-1);
		}
		
		st.push(i);
	}
	
	for(int i = size - 1; i >= 0; i--) {
		ans[i] == -1 ? cout << "X" : cout << ans[i];
		cout << " ";
	}
}