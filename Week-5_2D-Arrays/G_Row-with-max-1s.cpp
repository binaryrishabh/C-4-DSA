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
	
	int max_val = 0, row = -1;
	for(int i = 0; i < n; i++) {
		int row_sum = 0;
		for(int j = 0; j < m; j++) {			
			row_sum += vec[i][j];
		}
		if(max_val < row_sum) {
			max_val = row_sum;
			row = i;
		}
	}
	cout << row;
}