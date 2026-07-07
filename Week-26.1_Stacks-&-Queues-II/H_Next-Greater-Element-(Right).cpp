#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void reverse(vector<string>& ans) {
	int i = 0, j = ans.size() - 1;
	
	while(i <= j) {
		string str = ans[i];
		ans[i] = ans[j];
		ans[j] = str;
		
		i++;
		j--;
	}
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size;
	cin >> size;
	
	vector<int> vec(size, 0);
	
	for(int i = 0; i < size; i++) {
		cin >> vec[i];
	}
	
	stack<int> st;
	vector<string> ans;
	
	for(int i = vec.size() - 1; i >= 0; i--) {
		// remove all useless elements
		while(!st.empty() && st.top() <= vec[i]) {
			st.pop();
		}
		
		if(st.empty()) {
			ans.push_back("X");
		}
		else {
			ans.push_back(to_string(st.top()));
		}
		st.push(vec[i]);
	}
	
	reverse(ans);
	
	for(string str : ans) {
		cout << str << " ";
	}
}