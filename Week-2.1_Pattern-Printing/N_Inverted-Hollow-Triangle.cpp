#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	for(int i = n; i > 0; i--) {
		for(int s = n; s > i; s--) {
			cout << " ";
		}
		for(int j = 0; j < (2 * i) - 1; j++) {
			(((j & 1) == 0) && i == n || j == 0 || j == (2 * i) - 2)
				? cout << "*"
				: cout << " ";
		}
		cout << endl;
	}
}