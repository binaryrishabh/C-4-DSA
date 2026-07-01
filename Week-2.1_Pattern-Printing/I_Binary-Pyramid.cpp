#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	int binary = 0;
	for (int i = 0; i < n; i++) {
		int rowBinary = binary;
		binary == 0 ? binary = 1 : binary = 0;
		for (int j = 0; j <= i; j++) {
			rowBinary == 0 ? cout << 0 : cout << 1;
			rowBinary == 0 ? rowBinary = 1 : rowBinary = 0;
		}
		cout << endl;
	}
}