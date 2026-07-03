#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

struct Pair{
	char c;
	int count;
};

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