#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

// Optimal Approach-> Uses Binary Search
// T.C.-> O(NlogN), S.C. O(1)

int firstOccurence(vector<int>& vec, int queryValue) {
	int left = 0, right = vec.size() - 1, index = -1;
	
	while(left <= right) {
		int mid = left + (right - left) / 2;
		if(vec[mid] < queryValue) { // target is greater than current
			left = mid + 1;
		}
		else if(vec[mid] > queryValue) { // target is less than current
			right = mid - 1;
		}
		else { // target is equal to value
			index = mid;
			right = mid - 1;
		}
	}
	
	return index;
}

int lastOccurence(vector<int>& vec, int queryValue) {
	int left = 0, right = vec.size() - 1, index = -1;
	
	while(left <= right) {
		int mid = left + (right - left) / 2;
		if(vec[mid] < queryValue) { // target is greater than current value
			left = mid + 1;
		}
		else if(vec[mid] > queryValue) { // target is less tahn current value
			right = mid - 1;
		}
		else {
			index = mid;
			left = mid + 1;
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
	
	for(int i = 0; i < queries; i++) {
		int queryValue;
		cin >> queryValue;
		
		int first = firstOccurence(vec, queryValue);
		if(first == -1) {
			cout << first;
		}
		else {
			int last = lastOccurence(vec, queryValue);
			cout << first + 1 << " " << last + 1;
		}
		
		cout << endl;
	}
}