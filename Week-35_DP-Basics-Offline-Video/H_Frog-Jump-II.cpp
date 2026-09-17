#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

// Better Approach:- memoization DP
// T.C.-> O(N*K), S.C.-> O(N)

int rec(int index, vector<int>& dp, vector<int>& vec, int k) {
	if(index >= vec.size()) {
		return LLONG_MAX;
	}
	
	if(index == vec.size() - 1) {
		return 0;
	}
	
	if(dp[index] != -1) {
		return dp[index];
	}
	
	int jump = LLONG_MAX;
	for(int i = 1; i <= k; i++) {
		if(index + i < vec.size()) {
			jump = min(jump, abs(vec[index + i] - vec[index]) + rec(index + i, dp, vec, k));
		}
	}
	
	return dp[index] = jump;
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size, k;
	cin >> size >> k;
	
	vector<int> vec(size, 0);
	
	for(int i = 0; i < size; i++) {
		cin >> vec[i];
	}
	
	vector<int> dp(size, -1);
	
	cout << rec(0, dp, vec, k);
}




// Brute Force Approach:- Recursive
// T.C.-> O(K^n), S.C.-> O(n)
/*
int rec(int index, vector<int>& vec, int k) {
	if(index >= vec.size()) {
		return LLONG_MAX;
	}
	
	if(index == vec.size() - 1) {
		return 0;
	}
	
	int jump = LLONG_MAX;
	for(int i = 1; i <= k; i++) {
		if(index + i < vec.size()) {
			jump = min(jump, abs(vec[index + i] - vec[index]) + rec(index + i, vec, k));
		}
	}
	
	return jump;
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size, k;
	cin >> size >> k;
	
	vector<int> vec(size, 0);
	
	for(int i = 0; i < size; i++) {
		cin >> vec[i];
	}
		
	cout << rec(0, vec, k);
}
*/