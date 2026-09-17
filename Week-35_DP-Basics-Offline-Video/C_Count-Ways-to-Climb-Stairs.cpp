#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'


// Better Approach:- Iterative DP no space
// T.C.-> O(N), S.C.-> O(1)
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int stair;
	cin >> stair;
	
	if(stair < 3) {
		cout << stair;
		return 0;
	}
	
	const int MODULO = 1e9 + 7;
	
	vector<int> dp(stair + 1);
	
	int first = 1;
	int second = 2;
	int third = 0;
	
	for (int i = 3; i <= stair; i++) {
		third = (first + second) % MODULO;
		first = second;
		second = third;
	}
	
	cout << third;
}


// Better Approach:- Iterative DP using space
// T.C.-> O(N), S.C.-> O(N)
/*
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int stair;
	cin >> stair;
	
	if(stair < 3) {
		cout << stair;
		return 0;
	}
	
	const int MODULO = 1e9 + 7;
	
	vector<int> dp(stair + 1);
	
	dp[1] = 1;
	dp[2] = 2;
	
	for (int i = 3; i <= stair; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % MODULO;
	}
	
	cout << dp[stair];
}
*/

// Better Approach:- memoization DP
// T.C.-> O(N), S.C.-> O(N)
/*
int climb(int stair, vector<int>& dp, int MODULO) {
	if(stair < 0) {
		return 0;
	}
	
	if(stair == 0) {
		return 1;
	}
	
	if(dp[stair] != -1) {
		return dp[stair];
	}
	
	return dp[stair] = (climb(stair - 1, dp, MODULO) + climb(stair - 2, dp, MODULO)) % MODULO;
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int stair;
	cin >> stair;
	
	const int MODULO = 1e9 + 7;
	
	vector<int> dp(stair + 1, -1);
	
	cout << climb(stair, dp, MODULO);
}
*/


// Brute Force Approach:- Recursive 
// T.C.-> O(2^n - 1), S.C.-> O(2^n - 1)
/*
int climb(int stair) {
	if(stair < 0) {
		return 0;
	}
	
	if(stair == 0) {
		return 1;
	}
	
	return climb(stair - 1) + climb(stair - 2);
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int stair;
	cin >> stair;
	
	cout << climb(stair);
}
*/