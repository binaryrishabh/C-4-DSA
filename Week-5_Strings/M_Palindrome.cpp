#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	
	int l = 0, r = s.size() - 1;
	
	while(l <= r) {
		if(s[l] != s[r]) {
			cout << "NO";
			return 0;
		}
		l++;
		r--;
	}
	cout << "YES";
}