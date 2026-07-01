#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, query;
	cin >> n >> query;
	
	for(int i = 0; i < query; i++) {
		int type, index;
		cin >> type >> index;
		
		// Use 1LL to ensure we are shifting a 64-bit integer
		int mask = (1LL << index);
		
		if(type == 1) { // check the ith index.
			if(n & mask) cout << "YES";
			else cout << "NO";
		}
		else if(type == 2) { // set the ith bit.
			n |= mask;
			cout << n;
		}
		else if(type == 3) { // unset the ith bit.
			mask = ~mask;
			n &= mask;
			cout << n;
		}
		else { // toggle the ith bit.
			n ^= mask;
			cout << n;
		}
		
		cout << endl;
	}
}