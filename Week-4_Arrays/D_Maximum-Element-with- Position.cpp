#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size;
	cin >> size;
	
	int max_val = INT_MIN, pos = -1;
	
	for(int i = 0; i < size; i++) {
		int val;
		cin >> val;
		
		if(max_val < val) {
			max_val = val;
			pos = i;
		}
	}
	
	cout << max_val << " " << pos + 1;
}