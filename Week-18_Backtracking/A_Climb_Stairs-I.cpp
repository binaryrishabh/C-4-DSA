#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void jump(int path, int n, vector<int> vec) {
	if(path == n) {
		for(const auto&val : vec) {
			cout << val << " ";
		}
		cout << endl;
		return;
	}
	if(path > n) return;
	
	vec.push_back(1);
	jump(path + 1, n, vec);
	vec.pop_back();
	
	vec.push_back(2);
	jump(path + 2, n, vec);
	vec.pop_back();
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	vector<int> vec;
	
	jump(0, n, vec);
}