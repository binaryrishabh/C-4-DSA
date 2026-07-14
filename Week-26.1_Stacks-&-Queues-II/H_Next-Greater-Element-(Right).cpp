#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

// Optimal Approach 
// T.C.-> O(N), S.C.-> O(N)

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
		while(!st.empty() && st.top() <= vec[i]) {
			st.pop();
		}
		
		if(!st.empty()) {
			ans.push_back(st.top());
		}
		else {
			ans.push_back(-1);
		}
		
		st.push(vec[i]);
	}
	
	for(int i = ans.size() - 1; i >= 0; i--) {
		ans[i] == -1 ? cout << "X" : cout << ans[i];
		cout << " ";
	}
}


// Best Approach but requires reverse of ans.
// T.C.-> O(N), S.C.-> O(N)
/*
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
*/