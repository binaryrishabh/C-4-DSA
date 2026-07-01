#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void hcf(int a, int b) {	
	
	int min_val = min(a, b);
	int HCF;
	for(int i = 1; i <= min_val; i++) {
		if(a % i == 0 && b % i == 0) HCF = i;
	}
	
	cout << HCF;
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int a, b;
	cin >> a >> b;
	
	hcf(a, b);
}