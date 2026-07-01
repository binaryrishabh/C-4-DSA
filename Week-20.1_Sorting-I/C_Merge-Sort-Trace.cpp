#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void merge(vector<int>& vec, int left, int mid, int right) {
	int i = left, j = mid + 1;
	
	vector<int> temp;
	
	while(i <= mid && j <= right) {
		if(vec[i] < vec[j]) {
			temp.push_back(vec[i++]);
		}
		else {
			temp.push_back(vec[j++]);
		}
	}
	
	while(i <= mid) {
		temp.push_back(vec[i++]);
	}
	
	while(j <= right) {
		temp.push_back(vec[j++]);
	}
	
	cout << "Merge: [" << left << " " << right << "] -> ";
	
	int ptr = 0;
	for(int v = left; v <= right; v++) {
		cout << temp[ptr] << " ";
		vec[v] = temp[ptr++];
	}
	cout << endl;
}

void mergeSort(vector<int>& vec, int left, int right) {
	if(left == right) return;
	
	cout << "Divide: [" << left << " " << right << "]" << endl;
	
	// calculate mid
	int mid = left + (right - left) / 2;
	
	// sort the left part of the array.
	mergeSort(vec, left, mid);
	
	// sort the right part of the array
	mergeSort(vec, mid + 1, right);
	
	merge(vec, left, mid, right);
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
	
	mergeSort(vec, 0, size - 1);
}