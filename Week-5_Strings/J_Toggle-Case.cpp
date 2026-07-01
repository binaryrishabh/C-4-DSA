#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	
	for(int i = 0; i < s.size(); i++) {
		char ch = s[i];
		
		if(ch >= 97 && ch <= 122) { // lowecase -> Uppercase
			cout << (char)(ch - 32);
		}
		else {
			cout << (char)(ch + 32);
		}
	}
}