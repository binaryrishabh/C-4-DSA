#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

// Optimal Approach => T.C. => O(N^2), S.C. => O(1)
int merge(vector<int>& vec, int left, int mid, int right) {
	int i = left, j = mid + 1;
	
	int inversion = 0;
	
	vector<int> temp;
	while(i <= mid && j <= right) {
		if(vec[i] <= vec[j]) {
			temp.push_back(vec[i++]);
		}
		else {
			inversion += mid - i + 1;
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
		
	return inversion;
}

int mergeSort(vector<int>& vec, int left, int right) {
	if(left == right) return 0;
	
	// Calculate mid
	int mid = left + (right - left) / 2;
	
	// Sort the left part
	int ans1 = mergeSort(vec, left, mid);
	
	// Sort the right part
	int ans2 = mergeSort(vec, mid + 1, right);
	
	int ans3 = merge(vec, left, mid, right);
	
	return ans1 + ans2 + ans3;
}

int countInversion(vector<int>& vec) {
	return mergeSort(vec, 0, vec.size() - 1);
}



// Worst Approach => T.C. => O(N^2), S.C. => O(1)
// int countInversion(vector<int> vec) {
// 	int count = 0;
// 	
// 	for(int i = 0; i < vec.size(); i++) {
// 		for(int j = i + 1; j < vec.size(); j++) {
// 			if(vec[i] > vec[j]) count++;
// 		}
// 	}
// 	
// 	return count;
// }

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
	
	cout << countInversion(vec) << endl;
}