#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int merge(vector<int>& vec, int left, int mid, int right) {
	int i = left, j = mid + 1;
	
	vector<int> temp;
	
	int reversePair = 0;
	
	while(i <= mid && j <= right) {
		if(vec[i] <= vec[j]) {
			temp.push_back(vec[i++]);
		}
		else {
			int x = i;
			while(x <= mid && vec[x] <= 2 * vec[j]) {
				x++;
			}
			reversePair += mid - x + 1;
						
			temp.push_back(vec[j++]);
		}
	}
	
	while(i <= mid) {
		temp.push_back(vec[i++]);
	}
	
	while(j <= right) {
		temp.push_back(vec[j++]);
	}
	
	int ptr = 0;
	for(int v = left; v <= right; v++) {
		vec[v] = temp[ptr++];
	}
	
	return reversePair;
}

int mergeSort(vector<int>& vec, int left, int right) {
	// Only one element is left
	if(left ==  right) return 0;
	
	// Calculate mid
	int mid = left + (right - left) / 2;
	
	// Sort left part of array
	int ans1 = mergeSort(vec, left, mid);
	
	// Sort right part of array
	int ans2 = mergeSort(vec, mid + 1, right);
	
	// Merge the left and right sorted arrays.
	int ans3 = merge(vec, left, mid, right);
	
	return ans1 + ans2 + ans3;
}

int reversePair(vector<int>& vec) {
	return mergeSort(vec, 0, vec.size() - 1);
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
	
	cout << reversePair(vec) << endl;
}