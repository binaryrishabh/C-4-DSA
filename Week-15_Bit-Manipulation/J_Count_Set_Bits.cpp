#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

// Coutning only set bits.
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, count = 0;
	cin >> n;
	
	while(n > 0) {
		n &= (n - 1);
		count++;
	}
	
	cout << count;
}

// Checking all the bits.
// signed main() {
// 	cin.tie(nullptr)->sync_with_stdio(false);
// 	int n, count = 0;
// 	cin >> n;
	
// 	while(n > 0) {
// 		if((n & 1) == 1) count++;
// 		n >>= 1;
// 	}
	
// 	cout << count;
// }