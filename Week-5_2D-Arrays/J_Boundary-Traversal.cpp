#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> vec(n, vector<int>(m, 0));
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> vec[i][j];
		}
	}
	
	if(n > 0 && m > 0) {
		for(int j = 0; j < m; j++) {
			cout << vec[0][j] << " ";
		}
	}
	
	if(n > 1) {
		for(int i = 1; i < n; i++) {
			cout << vec[i][m - 1] << " ";
		}
	}
	
	if(n > 1 && m > 1) {
		for(int j = m - 2; j >= 0; j--) {
			cout << vec[n - 1][j] << " ";
		}
	}
	
	if(n > 2 && m > 2) {
		for(int i = n - 2; i > 0; i--) {
			cout << vec[i][0] << " ";
		}
	}
}