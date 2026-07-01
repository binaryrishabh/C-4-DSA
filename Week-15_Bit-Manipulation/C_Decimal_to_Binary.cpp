#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	if(n == 0) { // handle the edge case 0 separately
		cout << n;
		return 0;
	}
	
	int highestPossiblePower = 1;
	while(highestPossiblePower <= n) {
		highestPossiblePower *= 2;
	}
	highestPossiblePower /= 2;
	
	while(highestPossiblePower > 0) {
		if(highestPossiblePower <= n) {
			n -= highestPossiblePower;
			cout << 1;
		}
		else cout << 0;
		
		highestPossiblePower /= 2;
	}
}