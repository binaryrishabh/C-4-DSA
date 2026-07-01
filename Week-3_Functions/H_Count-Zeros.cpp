#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void zeros(int n) {
	if(n == 0) {
		cout << 1;
		return;
	}
	
	int zero = 0;
	while(n > 0) {
		if(n % 10 == 0) zero++;
		n /= 10;
	}
	
	cout << zero;
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;

	zeros(n);
}