#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int fact(int n) {
	int fact = 1;
	
	for(int i = 1; i <= n; i++) {
		fact *= i;
	}
	
	return fact;
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, r;
	cin >> n >> r;
	
	cout << fact(n) / (fact(r) * fact(n - r));
}