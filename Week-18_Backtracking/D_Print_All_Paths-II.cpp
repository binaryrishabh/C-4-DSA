#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void move(int row, int col, int n, int m, vector<char> vec, vector<vector<bool>> block) {
	if(row == n && col == m) {
		for(const auto& val : vec) cout << val;
		cout << endl;
		return;
	}
	if(row > n || col > m || block[row][col]) return;
	
	vec.push_back('R');
	move(row, col + 1, n, m, vec, block);
	vec.pop_back();
	
	vec.push_back('D');
	move(row + 1, col, n, m, vec, block);
	vec.pop_back();
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	// n -> row; m -> col;
	int n, m;
	cin >> n >> m;
	
	vector<vector<bool>> block(n + 1, vector<bool>(m + 1));
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			int val;
			cin >> val;
			
			block[i][j] = val;
		}
	}
	
	vector<char> vec;
	move(1, 1, n, m, vec, block);
}