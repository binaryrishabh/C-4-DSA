#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int power(int x, int n) {
	if(n == 1) return x;
	
	return x * power(x, n - 1);
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int x, n;
	cin >> x >> n;
	
	cout << power(x, n);
}