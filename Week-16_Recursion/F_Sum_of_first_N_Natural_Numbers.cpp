#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int sum(int n) {
	if(n == 0) return 0;
	
	return n + sum(n - 1);
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	cout << sum(n);
}