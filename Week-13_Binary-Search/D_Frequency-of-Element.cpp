#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

// Improved Approach-> Uses Maps
// T.C.-> O(N), S.C. O(N)
/*
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size, queries;
	cin >> size >> queries;
	
	vector<int> vec(size, 0);
	
	unordered_map<int, int> map;
	
	for(int i = 0; i < size; i++) {
		int val;
		cin >> val;
		
		map[val]++;
	}
	
	for(int i = 0; i < queries; i++) {
		int queryValue;
		cin >> queryValue;
		
		cout << map[queryValue] << endl;
	}
}
*/


// Improved Approach-> Uses Binary Search
// T.C.-> O(NlogN), S.C. O(logN)

int firstOccurence(vector<int>& vec, int queryValue) {
	int left = 0, right = vec.size() - 1, index = -1;
	
	while(left <= right) {
		int mid = left + (right - left) / 2;
		
		if(vec[mid] < queryValue) { // target is greater than the current value
			left = mid + 1;
		}
		else if(vec[mid] > queryValue) { // targte is less than the current value
			right = mid - 1;
		}
		else { // target is equal to the current value
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
		
		if(vec[mid] < queryValue) { // target is less than the current value
			left = mid + 1;
		}
		else if(vec[mid] > queryValue) { // target is greater than the current value
			right = mid - 1;
		}
		else { // target is equal to the current value
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
	
	sort(vec.begin(), vec.end());
	
	for(int i = 0; i < queries; i++) {
		int queryValue;
		cin >> queryValue;
		
		int firstIndex = firstOccurence(vec, queryValue);
		
		if(firstIndex == -1) {
			cout << 0;
		}
		else {
			int lastIndex = lastOccurence(vec, queryValue);	
			cout << lastIndex - firstIndex + 1;
		}
		
		cout << endl;
	}
}
