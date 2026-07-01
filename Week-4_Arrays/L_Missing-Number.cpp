#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void missing(int size) {
	int miss = 0;
	
	for(int i = 0; i < size; i++) {
		int val;
		cin >> val;
		
		miss ^= val;
	}
	
	cout << miss;
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int test;
	cin >> test;
	
	for(int t = 0; t < test; t++) {
		int size;
		cin >> size;
		
		missing(size);
		
		cout << endl;
	}
}