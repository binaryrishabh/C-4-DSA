#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	int sum = 0;
	while(n > 0) {
		sum += n % 10;
		n /= 10;
	}
	
	cout << sum;
}