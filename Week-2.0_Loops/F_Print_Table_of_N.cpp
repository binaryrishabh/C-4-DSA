#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	for(int i = 1; i <= 10; i++) {
		cout << n << " * " << i << " = " << n * i << endl;
	}
}