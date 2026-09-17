#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'


// Optimal Approach:- Iterative DP
// T.C.-> O(N), S.C.-> O(1)

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	const int MODULO = 1e9 + 7;
	
	if(n < 2) {
		cout << n;
		return 0;
	}
	
	if(n == 2) {
		cout << 1;
		return 0;
	}
	
	int first = 0, second = 1, third = 1, fourth = -1;
	for(int i = 2; i < n; i++) {
		fourth = (first + second + third) % MODULO;
		first = second;
		second = third;
		third = fourth;
	}
	
	cout << fourth;
}


// Better Approach:- memoization DP
// T.C.-> O(N), S.C.-> O(N)
/*
int tribo(int n, vector<int>& dp, int MODULO) {
	if(dp[n] != -1) {
		return dp[n];
	}
	
	if(n < 2) {
		return dp[n] = n;
	}
	
	if(n == 2) {
		return dp[2] = 1;
	}
	
	return dp[n] = (tribo(n - 1, dp, MODULO) + tribo(n - 2, dp, MODULO) + tribo(n - 3, dp, MODULO)) % MODULO;
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	const int MODULO = 1e9 + 7;
	
	vector<int> dp(n + 1, -1);
	
	cout << tribo(n, dp, MODULO);
}
*/


// Brute Force Approach:- Recursive 
// T.C.-> O(3^n - 1), S.C.-> O(n)
/*
int tribo(int n) {
	if(n < 2) {
		return n;
	}
	if(n == 2) {
		return 1;
	}
	
	return tribo(n - 1) + tribo(n - 2) + tribo(n - 3);
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	cout << tribo(n);
}
*/