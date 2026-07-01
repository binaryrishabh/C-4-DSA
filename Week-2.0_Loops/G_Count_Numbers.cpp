#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	int pos = 0, neg = 0, even = 0, odd = 0;
	for(int i = 0; i < n; i++) {
		int val;
		cin >> val;
		
		if(val > 0) pos++;
		else if(val < 0) neg++;
		
		if((val & 1) == 0) even++;
		else odd++;
	}
	
	cout << pos << endl << neg << endl << even << endl << odd << endl;
}