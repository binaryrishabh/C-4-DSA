#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size, x;
	cin >> size >> x;
	
	for(int i = 0; i < size; i++) {
		int val;
		cin >> val;
		
		if(val == x) {
			cout << "YES";
			return 0;
		}
	}
	
	cout << "NO";
}