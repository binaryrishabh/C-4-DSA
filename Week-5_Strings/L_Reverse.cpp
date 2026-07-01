#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	
	for(int i = s.size() - 1; i >= 0; i--) {
		cout << s[i];
	}
}