#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	char ch;
	cin >> ch;
	
	if(ch >= 97 && ch <= 122) cout << "Lowercase";
	else if(ch >= 65 && ch <= 90) cout << "Uppercase";
	else if(ch >= 48 && ch <= 57) cout << "Digit";
	else cout << "Special";
}