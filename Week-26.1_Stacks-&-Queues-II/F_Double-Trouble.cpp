#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

//Optimal Approach-> Moving from right to left
// T.C.-> O(N), O(N)

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



// Improved Approach-> Moving from left to right
// T.C.-> O(N), O(N)
/*
void reverse(string& str) {
	if(str.size() == 0) return;
	
	int i = 0, j = str.size() - 1;
	
	while(i < j) {
		char ch = str[i];
		str[i] = str[j];
		str[j] = ch;
		
		i++;
		j--;
	}
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	
	stack<char> st;
	
	for(char ch : s) {
		if(!st.empty() && st.top() == ch) {
			st.pop();
		}
		else {
			st.push(ch);
		}
	}
	
	string str = "";
	
	while(!st.empty()) {
		str += st.top();
		st.pop();
	}
	
	reverse(str);
	
	cout << str;
}
*/

// Brute-Force Approach
// T.C.-> O(N^2), O(N) will give TLE for this question 
// constraints -> 10^5
/*
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	
	while(true) {
		string t = "";
		
		int i;
		for(i = 0; i < s.size() - 1; i++) {
			if(s[i] == s[i + 1]) { // skip two characters
				i++;
			}
			else {
				t += s[i];
			}
		}
		
		if(i == (s.size() - 1)) {
			t += s[s.size() - 1];
		}
		
		if(s == t) break;
		s = t;
	}
	
	cout << s << endl;
}
*/