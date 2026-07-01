#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> vec(n, vector<int>(n, 0));
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> vec[i][j];
		}
	}
	
	for(int j = 0; j < m; j++) {
		int col_sum = 0;
		for(int i = 0; i < n; i++) {
			col_sum += vec[i][j];
		}
		cout << col_sum << " ";
	}
}