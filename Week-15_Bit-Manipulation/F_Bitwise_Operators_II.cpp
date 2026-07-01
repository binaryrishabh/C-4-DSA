#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size;
	cin >> size;
	
	int num;
	cin >> num;
	
	int And = num, Or = num, Xor = num;
	
	for(int i = 1; i < size; i++) {
		int val;
		cin >> val;
		
		And &= val;
		Or |= val;
		Xor ^= val;
	}
	
	cout << And << " " << Or << " " << Xor;
}