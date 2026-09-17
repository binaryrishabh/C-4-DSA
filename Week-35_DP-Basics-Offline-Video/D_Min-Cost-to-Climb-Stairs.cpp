#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'


// Optimal Approach:- Iterative DP Using no space
// T.C.-> O(N), S.C.-> O(1)

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size;
	cin >> size;
	
	vector<int> vec(size, 0);
	
	for(int i = 0; i < size; i++) {
		cin >> vec[i];
	}
	
	if(size < 2) {
		cout << vec[0];
		return 0;
	}
	
	int first = vec[0];
	int second = vec[1];
	int third = 0;
	
	for(int i = 2; i < size; i++) {
		third = vec[i] + min(first, second);
		first = second;
		second = third;
	}
	
	cout << min(first, second);
}



// Improved Approach:- Iterative DP Using space
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
	
	if(size < 2) {
		cout << vec[0];
		return 0;
	}
	
	vector<int> dp(size, 0);
	
	dp[0] = vec[0];
	dp[1] = vec[1];
		
	for(int i = 2; i < size; i++) {
		dp[i] = vec[i] + min(dp[i - 1], dp[i - 2]);
	}
	
	cout << min(dp[size - 1], dp[size - 2]);
}
*/


// Better Approach:- memoization DP
// T.C.-> O(N), S.C.-> O(N)

// i. First Approach
/*
int rec(int index, vector<int>& dp, vector<int>& vec) {
	if(index >= vec.size()) {
		return 0;
	}
	
	int one = rec(index + 1, dp, vec);
	int two = rec(index + 2, dp, vec);
	
	return vec[index] + min(one, two);
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size;
	cin >> size;
	
	vector<int> vec(size, 0);
	
	for(int i = 0; i < size; i++) {
		cin >> vec[i];
	}
	
	if(size < 2) {
		cout << vec[0];
		return 0;
	}
	
	vector<int> dp(size + 1, -1);
		
	int one = rec(0, dp, vec);
	int two = rec(1, dp, vec);
	
	cout << min(one, two);
}*/

// ii. Second Approach
/*
int rec(int index, vector<int>& dp, vector<int>& vec) {
	if(index + 1 >= vec.size()) {
		return 0;
	}
	
	int one = 0;
	if(index + 1 < vec.size()) {
		one = vec[index + 1] + rec(index + 1, dp, vec);
	}
	
	int two = 0;
	if(index + 2 < vec.size()) {
		two = vec[index + 2] + rec(index + 2, dp,  vec);
	}
	
	return dp[index] = min(one, two);
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size;
	cin >> size;
	
	vector<int> vec(size + 1, 0);
	
	for(int i = 1; i <= size; i++) {
		cin >> vec[i];
	}
	
	if(size < 2) {
		cout << vec[1];
		return 0;
	}
	
	vector<int> dp(size + 1, -1);
		
	cout << rec(0, dp, vec);
}
*/



// Brute Force Approach:- Recursive
// T.C.-> O(2^n - 1), S.C.-> O(n)

// i. First Approach
/*
int rec(int index, vector<int>& vec) {
	if(index >= vec.size()) {
		return 0;
	}
	
	int one = rec(index + 1, vec);
	int two = rec(index + 2, vec);
	
	return vec[index] + min(one, two);
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size;
	cin >> size;
	
	vector<int> vec(size, 0);
	
	for(int i = 0; i < size; i++) {
		cin >> vec[i];
	}
	
	if(size < 2) {
		cout << vec[0];
		return 0;
	}

	int one = rec(0, vec);
	int two = rec(1, vec);
	
	cout << min(one, two);
}
*/

// ii. Second Approach
/*
int rec(int index, vector<int>& vec) {
	if(index + 1 >= vec.size()) {
		return 0;
	}
	
	int one = 0;
	if(index + 1 < vec.size()) {
		one = vec[index + 1] + rec(index + 1, vec);
	}
	
	int two = 0;
	if(index + 2 < vec.size()) {
		two = vec[index + 2] + rec(index + 2, vec);
	}
	
	return min(one, two);
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size;
	cin >> size;
	
	vector<int> vec(size + 1, 0);
	
	for(int i = 1; i <= size; i++) {
		cin >> vec[i];
	}
	
	if(size < 2) {
		cout << vec[1];
		return 0;
	}
		
	cout << rec(0, vec);
}
*/