#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	getline(cin, s);
	
	for(int i = 0; i < s.size(); i++) {
		if(s[i] != ' ') cout << s[i];
	}
}