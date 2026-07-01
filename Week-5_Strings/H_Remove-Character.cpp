#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	char ch;
	cin >> s >> ch;
	
	for(int i = 0; i < s.size(); i++) {
		if(s[i] != ch) cout << s[i];
	}
}