#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	
	int first[n];
	
	for(int i = 0; i < n; i++) {
		int val;
		cin >> val;
		
		first[i] = val;
	}
	
	int second[m];
	
	for(int i = 0; i < m; i++) {
		int val;
		cin >> val;
		
		second[i] = val;
	}
	
	int third[n + m];
	
	int p = 0, q = 0, r = 0;
	while(p < n && q < m) {
		if(first[p] < second[q]) {
			third[r++] = first[p++];
		}
		else {
			third[r++] = second[q++];
		}
	}
	
	while(p < n) {
		third[r++] = first[p++];
	}
	
	while(q < m) {
		third[r++] = second[q++];
	}
	
	for(int val : third) {
		cout << val << " ";
	}
}