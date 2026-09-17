#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'


// Approach:- Greedy
// T.C.-> O(NlogN), S.C.-> O(logN)
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size, limit;
	cin >> size >> limit;
	
	vector<int> vec(size, 0);
	
	for(int i = 0; i < size; i++) {
		cin >> vec[i];
	}
	
	sort(vec.begin(), vec.end());
	
	int l = 0, r = size - 1, boat = 0;
	while(l <= r) {
		if(l != r && vec[l] + vec[r] <= limit) {
			l++;
		}
		boat++;
		r--;
	}
	
	cout << boat;
}