#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

// Improved => T.C. -> O(N), S.C. -> O(1)
void prime(int n) {
	for(int i = 2; i * i <= n; i++) {
		if(n % i == 0) {
			cout << "Not Prime";
			return;
		}
	}
	cout << "Prime";
}

// Brute Force => T.C. -> O(N), S.C. -> O(1)
// void prime(int n) {
// 	for(int i = 2; i < n; i++) {
// 		if(n % i == 0) {
// 			cout << "Not Prime";
// 			return;
// 		}
// 	}
// 	cout << "Prime";
// }

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	if(n == 1) {
		cout << "Not Prime";
		return 0;
	}
	
	prime(n);
}