#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

// Optimal Approach:- Iterative DP No space
// T.C.-> O(N^2), S.C.-> O(1)

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	vector<vector<int>> vec(n);
	
	for(int i = 0; i < n; i++) {
		vec[i] = vector<int>(i + 1, LLONG_MAX);
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= i; j++) {
			cin >> vec[i][j];
		}
	}
	
	for(int i = 1; i < n; i++) {
		vec[i][0] += vec[i - 1][0]; // Left edges
		vec[i][i] += vec[i - 1][i - 1]; // Right edges
	}
	
	for(int i = 1; i < n; i++) {
		for(int j = 1; j < i; j++) {
			vec[i][j] += min(vec[i - 1][j], vec[i - 1][j - 1]);
		}
	}
	
	int cost = LLONG_MAX;
	for(int j = 0; j < n; j++) {
		cost = min(cost, vec[n - 1][j]);
	}
	
	cout << cost;
}


// Better Approach:- memoization DP
// T.C.-> O(N^2), S.C.-> O(N^2)
/*
int rec(int row, int col, vector<vector<int>>& dp, int n, vector<vector<int>>& vec) {	
	if(row >= n || col > row) {
		return LLONG_MAX;
	}
	
	if(row == n - 1) {
		return vec[row][col];
	}
	
	if(dp[row][col] != -1) {
		return dp[row][col];
	}
	
	int down = rec(row + 1, col, dp, n, vec);
	int right = rec(row + 1, col + 1, dp, n, vec);
	
	return dp[row][col] = vec[row][col] + min(down, right);
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	vector<vector<int>> vec(n, vector<int>(n, 0));
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= i; j++) {
			cin >> vec[i][j];
		}
	}
	
	vector<vector<int>> dp(n, vector<int>(n, -1));
	
	cout << rec(0, 0, dp, n, vec);
}
*/



// Brute Force Approach:- Recursive
// T.C.-> O(2^n), S.C.-> O(n)
/*
int rec(int row, int col, int n, vector<vector<int>>& vec) {
	if(row >= n || col > row) {
		return LLONG_MAX;
	}
	
	if(row == n - 1) {
		return vec[row][col];
	}
	
	int down = rec(row + 1, col, n, vec);
	int right = rec(row + 1, col + 1, n, vec);
	
	return vec[row][col] + min(down, right);
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	vector<vector<int>> vec(n, vector<int>(n, 0));
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= i; j++) {
			cin >> vec[i][j];
		}
	}
	
	cout << rec(0, 0, n, vec);
}
*/