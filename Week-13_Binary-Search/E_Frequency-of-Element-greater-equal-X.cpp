#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

// Optimal Approach-> Uses Binary Search
// T.C.-> O(NlogN), S.C. O(logN)

int firstOccurence(vector<int>& vec, int queryValue) {
	int left = 0, right = vec.size() - 1, index = vec.size();
	
	while(left <= right) {
		int mid = left + (right - left) / 2;
		
		if(vec[mid] < queryValue) { // target is greater than the current value
			left = mid + 1;
		}
		else { // target is less than equal to the current value
			index = mid;
			right = mid - 1;
		}
	}
	
	return index;
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
		
		int firstIndex = firstOccurence(vec, queryValue);
		cout << size - firstIndex << endl;
	}
}