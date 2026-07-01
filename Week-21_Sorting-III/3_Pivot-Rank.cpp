// Q.
// Given an array of size N and an integer X, 
// we need to find the correct sorted position for X.
// X will be part of the array.


#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

// Optimal:- Counting. T.C. -> O(N), S.C. -> O(1)
void pivot_rank(vector<int>& vec, int x) {
	int index = 0;
	for(int val : vec) {
		if(val < x) {
			index++;
		}
	}
	
	cout << index;
}

// Worst:- Using Inbuilt sort. T.C. -> O(NlogN), S.C. -> O(logN)
// void pivot_rank(vector<int>& vec, int x) {
// 	sort(vec.begin(), vec.end());
	
// 	for(int i = 0; i < vec.size(); i++) {
// 		if(vec[i] == x) {
// 			cout << i;
// 		}
// 	}
// }

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size, x;
	cin >> size >> x;
	
	vector<int> vec(size, 0);
	
	for(int i = 0; i < size; i++) {
		cin >> vec[i];
	}
	
	pivot_rank(vec, x);
}