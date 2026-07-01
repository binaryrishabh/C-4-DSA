#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	for(int i = 0; i < 5; i++) {
		for(int j = 5; j > i; j--) {
			cout << "*";
		}
		cout << endl;
	}
}