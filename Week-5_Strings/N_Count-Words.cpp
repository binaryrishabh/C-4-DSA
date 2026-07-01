#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	getline(cin, s);
	
	int word = 1;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == ' ') word++;
	}
	
	cout << word;
}