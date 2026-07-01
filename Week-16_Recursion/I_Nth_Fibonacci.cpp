#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int fibo(int n) {
	if(n <= 2) return n - 1;
	
	return fibo(n - 1) + fibo(n - 2);
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	cout << fibo(n);
}