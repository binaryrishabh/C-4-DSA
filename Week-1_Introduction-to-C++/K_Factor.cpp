#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, f;
	cin >> n >> f;
	
	if(n % f == 0) cout << "Yes";
	else cout << "No";
}