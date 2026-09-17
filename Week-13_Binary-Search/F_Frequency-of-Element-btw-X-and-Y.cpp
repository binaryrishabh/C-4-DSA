#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

// Optimal Approach-> Uses Binary Search
// T.C.-> O(NlogN), S.C. O(logN)

int xIndex(int x, vector<int>& vec) {
	int left = 0, right = vec.size() - 1, index = vec.size();
	
	while(left <= right) {
		int mid = left + (right - left) / 2;
		
		if(vec[mid] < x) { // target is greater than the current value
			left = mid + 1;
		}
		else {
			index = mid;
			right = mid - 1;
		}
	}
	
	return index;
}

int yIndex(int y, vector<int>& vec) {
	int left = 0, right = vec.size() - 1, index = -1;
	
	while(left <= right) {
		int mid = left + (right - left) / 2;
		
		if(vec[mid] > y) { // target is less than the current value
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
	
	sort(vec.begin(), vec.end());
	
	for(int i = 0; i < queries; i++) {
		int x, y;
		cin >> x >> y;
		
		
		
		int left = xIndex(x, vec);
		int right = yIndex(y, vec);
		
		x <= y ? cout << right - left + 1 : cout << 0;
		
		cout << endl;
	}
}