#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void inverted(int n) {
	for(int i = 0; i < n; i++) {
		cout << "*";
	}
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	for(int i = 1; i < (2 * n); i++) {
		int starCol = i <= n ? n - i + 1 : i - n + 1;
		inverted(starCol);
		
		int spaceCol = i <= n ? (2 * i) - 1 : (((2 * n) - i) * 2) - 1;
		for(int j = 0; j < spaceCol; j++) {
			cout << " ";
		}
		inverted(starCol);
		cout << endl;
	}
}