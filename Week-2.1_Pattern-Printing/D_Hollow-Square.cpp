#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			(i == 0 || i == n - 1 || j == 0 || j == n - 1) 
				? cout << "*"
				: cout << " ";
		}
		cout << endl;
	}
}