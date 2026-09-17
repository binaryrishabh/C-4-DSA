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
	
	long long first = 0, second = 1, third = 2;
	for(int i = 1; i < n; i++) {
		third = (first + second) % MODULO;
		first = second;
		second = third;
	}
	
	cout << third;
}


// Better Approach:- memoization DP
// T.C.-> O(N), S.C.-> O(N)
/*
int fibo(int n, vector<int>& dp, int MODULO) {
	if(dp[n] != -1) {
		return dp[n];
	}
	
	if(n < 2) {
		return dp[n] = n;
	}
	
	return dp[n] = (fibo(n - 1, dp, MODULO) + fibo(n - 2, dp, MODULO)) % MODULO;
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	const int MODULO = 1e9 + 7;
	
	vector<int> dp(n + 1, -1);
	
	cout << fibo(n, dp, MODULO);
}
*/



// Brute Force Approach:- Recursive 
// T.C.-> O(2^n - 1), S.C.-> O(2^n - 1)
/*
int fiboRec(int n) {
	if(n < 2) {
		return n;
	}
	
	return fiboRec(n - 1) + fiboRec(n - 2);
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	cout << fiboRec(n);
}*/