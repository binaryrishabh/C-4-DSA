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
	
	for(int i = 0; i < vec.size(); i++) {
		while(!st.empty() && st.top() <= vec[i]) {
			st.pop();
		}
		
		if(!st.empty()) {
			cout << st.top();
		}
		else {
			cout<< "X";
		}
		
		st.push(vec[i]);
		cout << " ";
	}
}