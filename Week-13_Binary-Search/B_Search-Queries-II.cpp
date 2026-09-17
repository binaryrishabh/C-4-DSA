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
		map.insert({val, i});
	}
	
	for(int i = 0; i < queries; i++) {
		int queryValue;
		cin >> queryValue;
		
		if(map.find(queryValue) != map.end()) {
			cout << map[queryValue] + 1;
		}
		else {
			cout << -1;
		}
		
		cout << endl;
	}
}
*/


// Improved Approach-> Uses Binary Search
// T.C.-> O(NlogN), S.C. O(1)

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
		
		int left = 0, right = size - 1;
		int index = -1;
		while(left <= right) {
			int mid = left + (right - left) / 2;
			if(vec[mid] > queryValue) { // target is less than mid value
				left = mid + 1;
			}
			else if(vec[mid] < queryValue) { // target is greater than mid value
				right = mid - 1;
			}
			else { // target is equal to mid value
				index = mid + 1;
				break;
			}
		}
		
		cout << index << endl;
	}
}
