#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size;
	cin >> size;
	
	unordered_map<string, int> map;
	
	for(int i = 0; i < size; i++) {
		string val;
		cin >> val;
		
		for(auto& x : val) {
			x = tolower(x);
		}
		
		map[val]++;
	}
	
	int max_val = INT_MIN;
	for(const auto& [key, value] : map) {
		max_val = max(max_val, value);
	}
	
	cout << max_val;
}