#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void verticalTriangle(int n) {
	for(int i = 0; i < n; i++) {
		cout << "*";
	}
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	for(int i = 1; i < (2 * n); i++) {
		int starCol = i <= n ? i : (2 * n) - i;
		verticalTriangle(starCol);
		int spaceCol = i <= n ? (n - i) * 2 : (i - n) * 2;
		for(int j = 0; j < spaceCol; j++) {
			cout << " ";
		}
		verticalTriangle(starCol);
		cout << endl;
	}
}