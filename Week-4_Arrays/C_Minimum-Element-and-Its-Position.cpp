#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size;
	cin >> size;
	
	int min_val = INT_MAX, pos = -1;
	
	for(int i = 0; i < size; i++) {
		int val;
		cin >> val;
		
		if(min_val > val) {
			min_val = val;
			pos = i;
		}
	}
	
	cout << min_val << " " << pos + 1;
}