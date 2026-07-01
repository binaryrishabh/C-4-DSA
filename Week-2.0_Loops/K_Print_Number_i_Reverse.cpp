#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	if(n == 0) cout << n;
	
	while(n > 0) {
		cout << n % 10;
		n /= 10;
	}
}