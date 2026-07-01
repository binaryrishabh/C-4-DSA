#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int x, n;
	cin >> x >> n;
	
	int pow = 1;
	
	for(int i = 0; i < n; i++) {
		pow *= x;
	}
	
	cout << pow;
}