#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size;
	cin >> size;
	
	int sum = 0;
	
	for(int i = 0; i < size; i++) {
		int val;
		cin >> val;
		
		sum += val;
	}
	
	cout << sum;
}