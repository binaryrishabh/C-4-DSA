#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'


// Optimal Approach=> Using a counter
// T.C.-> O(N), S.C.-> O(1)
// signed main() {
// 	cin.tie(nullptr)->sync_with_stdio(false);
// 	string s;
// 	cin >> s;
	
// 	int brackets = 0, max_val = INT_MIN;
	
// 	for(char ch : s) {
// 		if(ch == '(') {
// 			brackets++;
// 		}
// 		else if(ch == ')') {
// 			brackets--;
// 		}
// 		max_val = max(max_val, brackets);
// 	}
	
// 	cout << max_val;
// }

// Improved Approach=> Using Stacks
// T.C.-> O(N), S.C.-> O(1)
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	
	int max_val = INT_MIN;
	
	stack<char> st;
	
	for(char ch : s) {
		if(ch == '(') {
			st.push('(');
		}
		else if(ch == ')') {
			st.pop();
		}
		max_val = max(max_val, (long long)st.size());
	}
	
	cout << max_val;
}