#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	for(int i = 4; i >= 0; i--) {
		for(int j = 0; j < 5; j++) {
			if(i == 0 || i == 4 || i == j) cout << "*";
			else cout << " ";
 		}
 		cout << endl;
	}
}