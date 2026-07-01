#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void pyramid(int n) {
	for(int i = 0; i <= n; i++) {
		cout << "*";
	}
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		pyramid(i);
		for(int j = 2; j < (n - i) * 2; j++) {
			cout << " ";
		}
		pyramid(i);
		cout << endl;
	}
}