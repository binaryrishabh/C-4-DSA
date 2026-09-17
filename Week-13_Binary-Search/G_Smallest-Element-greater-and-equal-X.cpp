#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

// Optimal Approach-> Uses Binary Search
// T.C.-> O(NlogN), S.C. O(logN)

int leftIndex(int x, vector<int>& vec) {
	int left = 0, right = vec.size() - 1, element = -1;
	
	while(left <= right) {
		int mid = left + (right - left) / 2;
		
		if(vec[mid] < x) {
			left = mid + 1;
		}
		else {
			element = vec[mid];
			right = mid - 1;
		}
	}
	
	return element;
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size, queries;
	cin >> size >> queries;
	
	vector<int> vec(size, 0);
	
	for(int i = 0; i < size; i++) {
		cin >> vec[i];
	}
	
	sort(vec.begin(), vec.end());
	
	for(int i = 0; i < queries; i++) {
		int queryValue;
		cin >> queryValue;
		
		int element = leftIndex(queryValue, vec);
		
		cout << element << endl;
	}
}