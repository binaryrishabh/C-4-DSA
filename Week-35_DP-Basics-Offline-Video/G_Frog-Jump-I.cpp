#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'


// Optimal Approach:- Iterative DP No space
// T.C.-> O(N), S.C.-> O(1)

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size;
	cin >> size;
	
	vector<int> vec(size, 0);
	
	for(int i = 0; i < size; i++) {
		cin >> vec[i];
	}
	
	if(size == 1) {
		cout << 0;
		return 0;
	}
	else if(size == 2) {
		cout << abs(vec[1] - vec[0]);
		return 0;
	}
	
	int first = 0;
	int second = abs(vec[1] - vec[0]);
	int third = 0;
	
	for(int i = 2; i < size; i++) {
		third = min(abs(vec[i] - vec[i - 1]) + second, abs(vec[i] - vec[i - 2]) + first);
		first = second;
		second = third;
	}
	
	cout << second;
}



// Optimal Approach:- Iterative DP Using space
// T.C.-> O(N), S.C.-> O(N)
/*
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size;
	cin >> size;
	
	vector<int> vec(size, 0);
	
	for(int i = 0; i < size; i++) {
		cin >> vec[i];
	}
	
	if(size == 1) {
		cout << 0;
		return 0;
	}
	else if(size == 2) {
		cout << abs(vec[1] - vec[0]);
		return 0;
	}
	
	vector<int> dp(size, -1);
	
	dp[0] = 0;
	dp[1] = abs(vec[1] - vec[0]);
	
	for(int i = 2; i < size; i++) {
		dp[i] = min(abs(vec[i] - vec[i - 1]) + dp[i - 1], abs(vec[i] - vec[i - 2]) + dp[i - 2]);
	}
	
	cout << dp[size - 1];
}
*/




// Better Approach:- memoization DP
// T.C.-> O(N), S.C.-> O(N)
/*
int rec(int index, vector<int>& dp, vector<int>& vec) {
	if(index >= vec.size()) {
		return INT_MAX;
	}
	
	if(index == vec.size() - 1) {
		return 0;
	}
	
	if(dp[index] != -1) {
		return dp[index];
	}
	
	int one = abs(vec[index] - vec[index + 1]) + rec(index + 1, dp, vec);
	
	int two = INT_MAX;
	if(index + 2 < vec.size()) {
		two = abs(vec[index] - vec[index + 2]) + rec(index + 2, dp, vec);
	}
	
	return dp[index] = min(one, two);
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size;
	cin >> size;
	
	vector<int> vec(size, 0);
	
	for(int i = 0; i < size; i++) {
		cin >> vec[i];
	}
	
	vector<int> dp(size, -1);
	
	cout << rec(0, dp, vec);
}*/



// Brute Force Approach:- Recursive
// T.C.-> O(2^n), S.C.-> O(n)
/*
int rec(int index, vector<int>& vec) {
	if(index >= vec.size()) {
		return INT_MAX;
	}
	
	if(index == vec.size() - 1) {
		return 0;
	}
	
	int one = abs(vec[index] - vec[index + 1]) + rec(index + 1, vec);
	
	int two = INT_MAX;
	if(index + 2 < vec.size()) {
		two = abs(vec[index] - vec[index + 2]) + rec(index + 2, vec);
	}
	
	return min(one, two);
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size;
	cin >> size;
	
	vector<int> vec(size, 0);
	
	for(int i = 0; i < size; i++) {
		cin >> vec[i];
	}
	
	cout << rec(0, vec);
}
*/