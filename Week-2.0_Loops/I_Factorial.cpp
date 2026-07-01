#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int factorial(int n) {
	int fact = 1;
	
	for(int i = 1; i <= n; i++) fact *= i;
	
	return fact;
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	cout << factorial(n);
}