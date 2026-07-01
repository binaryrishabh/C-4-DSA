#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	int two = 1;
	
	while(two <= n) {
		cout << two << " ";
		two *= 2;
	}
}