#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void factors(int n) {
	for(int i = n; i > 0; i--) {
		if(n % i == 0) cout << i << " ";
	}
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	factors(n);
}