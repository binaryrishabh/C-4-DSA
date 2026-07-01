// Q.
// Given an array and X, rearrange the elements such that
// All elements < x comes before all elements >= x.
// If multiple answers are possible, find any one. 
// You don't have to preserve the order.

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'


// Optimal:- Two Pointers. T.C. -> O(N), S.C. -> O(1)
// Known as ONE PASS APPROACH. In place no extra space
void rearrange(vector<int> vec, int pivot) {
	int i = 0, j = vec.size() - 1;
	
	while(i <= j) {
		if(vec[i] >= pivot) {
			int temp = vec[i];
			vec[i] = vec[j];
			vec[j] = temp;
			j--;
		}
		else {
			i++;
		}
	}
	
	for(const auto& val : vec) {
		cout << val << " ";
	}
}


// Better:- Count sort. T.C. -> O(N), S.C. -> O(1)
// TWO PASS APPROACH. Not inplace uses extra array
// void rearrange(vector<int> vec, int pivot) {
// 	vector<int> ans(vec.size(), 0);
	
// 	int ptr = 0;
// 	for(int val : vec) {
// 		if(val < pivot) {
// 			ans[ptr++] = val;
// 		}
// 	}
	
// 	for(int val : vec) {
// 		if(val >= pivot) {
// 			ans[ptr++] = val;
// 		}
// 	}
	
// 	for(const auto& val : ans) {
// 		cout << val << " ";
// 	}
// }


signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size, pivot;
	cin >> size >> pivot;
	
	vector<int> vec(size, 0);
	
	for(int i = 0; i < size; i++) {
		cin >> vec[i];
	}
	
	rearrange(vec, pivot);
}