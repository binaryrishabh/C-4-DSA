#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int digits(int n) {
	if(n == 0) return 0;
	
	return n % 10 + digits(n / 10);
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	cout << digits(n);
}