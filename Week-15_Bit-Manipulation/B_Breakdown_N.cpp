#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'


// ? Best optimal way T.C.=> O(logN) 
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	int highestPowerPossible = 1;
	while(highestPowerPossible <= n) {
		highestPowerPossible *= 2;
	}
	highestPowerPossible /= 2;
	
	
	while(n > 0) {
		if(highestPowerPossible <= n) {
			cout << highestPowerPossible << " ";
			
			n -= highestPowerPossible;
		}
		highestPowerPossible /= 2;
	}
}


// ? One way to code this question but it's T.C.=> O((logN)^2) 
// int power(int n) {
// 	int highestPowerPossible = 1;
// 	while(highestPowerPossible <= n) {
// 		highestPowerPossible *= 2;
// 	}
// 	return highestPowerPossible/2;
// }

// signed main() {
// 	cin.tie(nullptr)->sync_with_stdio(false);
	
// 	int n;
// 	cin >> n;
	
// 	while(n > 0) {
// 		int two = power(n);
// 		cout << two << " ";
// 		n -= two;
// 	}
// }