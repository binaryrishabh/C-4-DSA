#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'


// Optimal Approach:- Iterative DP No space
// T.C.-> O(N * M), S.C.-> O(1)

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
	
	for(int i = 1; i < n; i++) {
		vec[i][0] += vec[i - 1][0];
	}
	
	for(int j = 1; j < m; j++) {
		vec[0][j] += vec[0][j - 1];
	}
	
	for(int i = 1; i < n; i++) {
		for(int j = 1; j < m; j++) {
			vec[i][j] += min(vec[i - 1][j], vec[i][j - 1]);
		}
	}
	
	cout << vec[n - 1][m - 1];
}



// Better Approach:- memoization DP
// T.C.-> O(N * M), S.C.-> O(N * M)

/*
int rec(int row, int col, vector<vector<int>>& dp, int n, int m, vector<vector<int>>& vec) {
	if(row == n - 1 && col == m - 1) {
		return vec[row][col];
	}
	
	if(row >= n || col >= m) {
		return LLONG_MAX;
	}
	
	if(dp[row][col] != -1) {
		return dp[row][col];
	}
	
	int down = rec(row + 1, col, dp, n, m, vec);
	
	int right = rec(row, col + 1, dp, n, m, vec);
	
	return dp[row][col] = vec[row][col] + min(down, right);
}

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
	
	vector<vector<int>> dp(n, vector<int>(m, -1));
	
	cout << rec(0, 0, dp, n, m, vec);
}
*/



// Brute Force Approach:- Recursive
// T.C.-> O(2^(n + m)), S.C.-> O(n + m)
/*
int rec(int row, int col, int n, int m, vector<vector<int>>& vec) {
	if(row == n - 1 && col == m - 1) {
		return vec[row][col];
	}
	
	if(row >= n || col >= m) {
		return INT_MAX;
	}
	 
	int down = rec(row + 1, col, n, m, vec);
	
	int right = rec(row, col + 1, n, m, vec);
	
	return vec[row][col] + min(right, down);
}

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
	
	cout << rec(0, 0, n, m, vec);
}
*/