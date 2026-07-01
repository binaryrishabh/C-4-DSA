#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int a, b;
	cin >> a >> b;
	
	cout << (a & b) << " " << (a | b) << " " << (a ^ b);
}