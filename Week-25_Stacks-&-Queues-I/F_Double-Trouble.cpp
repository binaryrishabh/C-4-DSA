#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	
	stack<char> st;
	
	for(int i = s.size() - 1; i >= 0; i--) {
		char ch = s[i];
		if(!st.empty()) {
			if(ch == st.top()) {
				st.pop();
				continue;
			}
		}
		
		st.push(ch);
	}
	
	string str = "";
	while(!st.empty()) {
		str += st.top();
		st.pop();
	}
	
	cout << str;
}