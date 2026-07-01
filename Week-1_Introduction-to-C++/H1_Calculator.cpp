#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	
	cout << n << " + " << m << " = " << n + m << endl;
	cout << n << " - " << m << " = " << n - m << endl;
	cout << n << " * " << m << " = " << n * m << endl;
	cout << n << " / " << m << " = " << n / m << endl;
	cout << n << " % " << m << " = " << n % m << endl;
}