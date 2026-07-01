#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void merge(vector<int>& vec, int left, int right) {
	int mid = left + (right - left) / 2;
	
	int i = left;
	int j = mid + 1;
	int k = 0;
		
	vector<int> temp;
	while(i <= mid && j <= right) {	
		if(vec[i] < vec[j]) {
			temp.push_back(vec[i++]);
		}
		else {
			temp.push_back(vec[j++]);
		}
		k++;
	}
	
	while(i <= mid) {
		temp.push_back(vec[i++]);
	}
	
	while(j <= right) {
		temp.push_back(vec[j++]);
	}
	
	int ptr = 0;
	for(int i = left; i <= right; i++) {
		vec[i] = temp[ptr++];
	}
}

void mergeSort(vector<int>& vec, int left, int right) {
	// array of size 1 is already sorted.
	if(left == right) {
		return;
	}
	
	// divide the array into two-equal halves.
	int mid = left + (right - left) / 2;
		
	// sort the first half
	mergeSort(vec, left, mid);
	
	// sort the second half
	mergeSort(vec, mid + 1, right);
	
	merge(vec, left, right);
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size;
	cin >> size;
	
	vector<int> vec(size, 0);
	
	for(int i = 0; i < size; i++) {
		int val;
		cin >> val;
		
		vec[i] = val;
	}
	
	mergeSort(vec, 0, vec.size() - 1);
	
	for(const auto& val : vec) {
		cout << val << " ";
	}
}