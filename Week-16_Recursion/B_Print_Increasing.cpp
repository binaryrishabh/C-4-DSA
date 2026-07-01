#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void print(int n) {
	if(n == 0) return;
	print(n - 1);
	cout << n << endl;
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	print(n);
}