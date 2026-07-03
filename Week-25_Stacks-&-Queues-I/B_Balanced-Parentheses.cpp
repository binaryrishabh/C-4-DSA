#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

bool opening(char ch) {
	return ch == '(' || ch == '{' || ch =='[';
}

bool valid(stack<char>& st, char ch) {
	return (st.top() == '(' && ch == ')')
		|| (st.top() == '{' && ch == '}')
		|| (st.top() == '[' && ch == ']');
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int test;
	cin >> test;
	
	for(int t = 0; t < test; t++) {
		string str;
		cin >> str;
		
		stack<char> st;
		
		bool invalid = false;
		for(char ch : str) {
			if(opening(ch)) {
				st.push(ch);
			}
			else {
				if(st.empty() || !valid(st, ch)) {
					invalid = true;
					break;
				}
				st.pop();
			}
		}
		
		if(invalid || st.size() != 0) cout << "No";
		else if(st.size() == 0) cout << "Yes";
		
		cout << endl;
	}
}