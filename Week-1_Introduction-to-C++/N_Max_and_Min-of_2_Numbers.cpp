#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int a, b, max, min;
	cin >> a >> b;

	if(a >= b) {
		max = a;
		min = b;
	}
	else {
		max = b;
		min = a;
	}
	
	cout << "Min = " << min << endl << "Max = " << max;
}