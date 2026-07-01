#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	for (int i = 1; i < n * 2; i++) {
		int maxCol = i <= n ? i : (n * 2) - i;
		for (int j = 0; j < maxCol; j++) {
			cout << "* ";
		}
		cout << endl;
	}
}