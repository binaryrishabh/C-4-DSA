#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

bool place(int cows, int min_val, vector<int>& vec) {
	int lastIndex = 0;
	
	for(int i = 1; i < vec.size(); i++) {
		if(vec[i] - vec[lastIndex] >= min_val) {
			cows--;
			lastIndex = i;
		}
	}
	
	return cows <= 1;
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size, k;
	cin >> size >> k;
	
	vector<int> vec(size, 0);
	
	for(int i = 0; i < size; i++) {
		cin >> vec[i];
	}
	
	sort(vec.begin(), vec.end());
	
	int left = 0, right = vec[size - 1] - vec[0], ans = -1;
	
	while(left <= right) {
		int mid = left + (right - left) / 2;
		
		if(place(k, mid, vec)) {
			ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	
	cout << ans;
}