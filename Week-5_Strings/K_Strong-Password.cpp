#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;

	bool lowercase = false, uppercase = false, digit = false, special = false;
	
	for(char ch : s) {
		if(ch >= 48 && ch <= 57) digit = true;
		else if(ch >= 65 && ch <= 90) uppercase = true;
		else if(ch >= 97 && ch <= 122) lowercase = true;
		else special = true;
	}
	
	if(s.size() == 10 && digit && lowercase && uppercase && special) cout << "Strong";
	else cout << "Weak";
}