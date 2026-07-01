#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

// Bit Approach
// Single line approach
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	if(n == 0) {
		cout << "NO";
		return 0;
	}
	
	if((n & (n - 1)) == 0) cout << "YES";
	else cout << "NO";
}


// Loop approach
// signed main() {
// 	cin.tie(nullptr)->sync_with_stdio(false);
// 	int n;
// 	cin >> n;
	
// 	if(n == 0) {
// 		cout << "NO";
// 		return 0;
// 	}
	
// 	while(n > 1) {
// 		if((n & 1) == 1) {
// 			cout << "NO";
// 			return 0;
// 		}
// 		n >>= 1;
// 	}
	
// 	cout << "YES";
// }