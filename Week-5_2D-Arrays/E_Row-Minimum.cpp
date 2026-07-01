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
	
	for(int i = 0; i < n; i++) {
		int min_val = INT_MAX;
		for(int j = 0; j < m; j++) {
			min_val = min(min_val, vec[i][j]);
		}
		cout << min_val << " ";
	}
}