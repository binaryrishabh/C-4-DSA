#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	for(int i = 1; i < n * 2; i++) {
		int maxCol = i <= n ? i * 2 - 1 : (n * 2 - i) * 2 - 1;
		for(int j = 0; j <= maxCol; j++) {
			(j == 0 || j == maxCol - 1)
				? cout << "*"
				: cout << " ";
		}
		cout << endl;
	}
}