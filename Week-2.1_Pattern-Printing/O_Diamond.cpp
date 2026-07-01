#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	for(int i = 1; i < (2 * n); i++) {
		int spaceCol = i <= n ? n - i : i - n;
		for(int s = 0; s < spaceCol; s++) {
			cout << " ";
		}
		int starCol = i <= n ? (2 * i) - 1 : ((n * 2) - i) * 2 - 1;
		for(int j = 0; j < starCol; j++) {
			(j & 1) == 0
				? cout << "*"
				: cout << " ";
		}
		cout << endl;
	}
}