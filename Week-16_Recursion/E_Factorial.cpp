#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int fact(int n) {
	if(n < 1) return 1;
	
	return n * fact(n - 1);
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	cout << fact(n);
}