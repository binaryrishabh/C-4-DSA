#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	int rev = 0, num = n;
	while(num > 0) {
		rev = (rev * 10) + (num % 10);
		num /= 10;
	}
	
	if(rev == n) cout << "YES";
	else cout << "NO";
}