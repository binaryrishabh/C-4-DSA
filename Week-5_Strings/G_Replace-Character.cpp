#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	char ch1, ch2;
	cin >> s >> ch1 >> ch2;
	
	for(int i = 0; i < s.size(); i++) {
		if(s[i] != ch1) cout << s[i];
		else cout << ch2;
	}
}