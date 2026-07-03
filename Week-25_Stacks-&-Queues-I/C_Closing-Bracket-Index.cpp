#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	
	int p;
	cin >> p;
	
	
	stack<char> st;
	
	for(int i = 0; i < s.size(); i++) {
		char ch = s[i];
		
		if(ch == '(') {
			if(i == p) {
				st.push('x');
			}
			else {
				st.push('(');
			}
		}
		else if(ch == ')') {
			char t = st.top();
			if(t == 'x') {
				cout << i;
				return 0;
			}
			else {
				st.pop();
			}
		}
	}
	
	cout << -1;
}