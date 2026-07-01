#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void jump(int steps, int n, int k, vector<int> vec) {
	if(steps == n) {
		for(const auto& val : vec) cout << val << " ";
			cout << endl;
		return;
	}
	if(steps > n) return;
	
	for(int i = 1; i <= k; i++) {
		vec.push_back(i);
		jump(steps + i, n, k, vec);
		vec.pop_back();
	}
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	
	vector<int> vec;
	
	jump(0, n, k, vec);
}