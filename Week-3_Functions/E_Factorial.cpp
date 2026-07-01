#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void factorial(int n) {
	int fact = 1;
	
	for(int i = 1; i <= n; i++) {
		fact *= i;
	}
	
	cout << fact;
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	factorial(n);
}