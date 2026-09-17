#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int a, b;
	cin >> a >> b;
	
	bool found = false;
	if(a + b == 9 || a - b == 9 || a * b == 9 || (double)(a) / b == 9) {
		found = true;
	}
	
	if(found) {
		cout << "Nine";
	}
	else {
		cout << "Nein";
	}
}