#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string firstPersonFirstName, firstPersonLastName, lastPersonFirstName, lastPersonLastName;
	cin >> firstPersonFirstName >> firstPersonLastName >> lastPersonFirstName >> lastPersonLastName;
	
	if(firstPersonLastName == lastPersonLastName) cout << "YES";
	else cout << "NO";
}