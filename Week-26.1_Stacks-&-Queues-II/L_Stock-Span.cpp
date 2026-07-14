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
	
	stack<pair<int, int>> st;
	
	for(int i = 0; i < size; i++) {
		int count = 1;
		
		while(!st.empty() && st.top().first <= vec[i]) {
			count += st.top().second;
			st.pop();
		}
			
		st.push({vec[i], count});
		
		cout << st.top().second << " ";
	}
}