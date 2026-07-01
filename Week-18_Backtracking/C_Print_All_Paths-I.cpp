#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void move(int n, int m, vector<char> vec) {
	if(n == 1 && m == 1) {
		for(const auto& val : vec) cout << val;
		
		cout << endl;
		return;
	}
		
	if(n < 1 || m < 1) return;
		
	vec.push_back('R');
	move(n, m - 1, vec);
	vec.pop_back();
	
	vec.push_back('D');
	move(n - 1, m, vec);
	vec.pop_back();
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	
	vector<char> vec;
	
	move(n, m, vec);
}