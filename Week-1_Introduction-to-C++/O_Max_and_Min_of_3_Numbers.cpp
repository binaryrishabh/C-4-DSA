#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int a, b, c, max, min;
	cin >> a >> b >> c;

	if(a >= b && a >= c) {
		max = a;
		if(b >= c) min = c;
		else min = b;
	}
	else if(b >= a && b >= c) {
		max = b;
		if(a >= c) min = c;
		else min = a;
	}
	else {
		max = c;
		if(a >= b) min = b;
		else min = a;
	}
	
	cout << "Min = " << min << endl << "Max = " << max;
}