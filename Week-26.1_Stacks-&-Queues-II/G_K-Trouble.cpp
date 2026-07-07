#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

struct Pair{
	char c;
	int count;
};

// Approach Moving from right to left
// T.C.-> O(N), O(N)
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	int k;
	
	cin >> s >> k;
	
	stack<Pair> st;
	
	for(int i = s.size() - 1; i >= 0; i--) {
		char ch = s[i];
		if(!st.empty()) {
			Pair& pair = st.top();
			if(ch == pair.c) {
				if(pair.count == k - 1) {
					st.pop();
				}
				else {
					pair.count++;
				}
				continue;
			}
		}
	
		st.push({ch, 1});
	}
	
	string str = "";
	while(!st.empty()) {
		int cnt = st.top().count;
		while(cnt > 0) {
			str += st.top().c;
			cnt--;
		}
		st.pop();
	}
	
	cout << str;
}


// Approach Moving from left to right
// T.C.-> O(N), O(N)
/*
void reverse(string& ans) {
	if(ans.size() == 0) return;
	int i = 0, j = ans.size() - 1;
	
	while(i < j) {
		char ch = ans[i];
		ans[i] = ans[j];
		ans[j] = ch;
		i++;
		j--;
	}
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	int k;
	cin >> s >> k;
	
	stack<pair<char, int>> st;
	
	for(char ch : s) {
		if(!st.empty() && st.top().first == ch) {
			if(st.top().second == k - 1) {
				st.pop();
			}
			else {
				st.top().second++;
			}
		}
		else {
			st.push({ch, 1});
		}
	}
	
	string ans = "";
	while(!st.empty()) {
		while(st.top().second > 0) {
			ans += st.top().first;
			st.top().second--;
		}
		st.pop();
	}
	
	reverse(ans);
	
	cout << ans;
}
*/