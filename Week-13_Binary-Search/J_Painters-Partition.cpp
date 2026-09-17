#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

bool possible(int time, int k, vector<int>& vec) {
	
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size, k;
	cin >> size >> k;
	
	vector<int> vec(size, 0);
	
	int totalTime = 0;
	
	for(int i = 0; i < size; i++) {
		cin >> vec[i];
		totalTime += vec[i];
	}
	
	int left = 1, right = totalTime, ans = 1;
	
	while(left <= right) {
		int mid = left + (right - left) / 2;
		
		if(possible(mid, k, vec)) {
			ans = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	
	cout << ans;
}