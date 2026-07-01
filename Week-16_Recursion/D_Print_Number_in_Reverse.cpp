#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void reverse(int n) {
	if(n == 0) return;
	
	cout << n % 10;
	reverse(n/10);
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	if(n == 0) cout << 0;
	
	reverse(n);
}