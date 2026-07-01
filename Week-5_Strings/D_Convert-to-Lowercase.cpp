#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	char ch;
	cin >> ch;
	
	if(ch >= 65 && ch <= 90) cout << (char)(ch + 32);
	else cout << ch;
}