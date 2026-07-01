#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void intersection(vector<int> vec1, vector<int> vec2) {
	for(int val : vec1) {
		if(vec2[val] > 0) {
			cout << val << " ";
			vec2[val]--;
		}
	}
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int test;
	cin >> test;
	
	for(int t = 0; t < test; t++) {
		int n;
		cin >> n;
		
		vector<int> vec1(n);
		for(int i = 0; i < n; i++) {
			int val;
			cin >> val;
			
			vec1[i] = val;
		}
		
		int m;
		cin >> m;
		
		vector<int> vec2(1001, 0);
		for(int i = 0; i < m; i++) {
			int val;
			cin >> val;
			
			vec2[val]++;
		}
		
		intersection(vec1, vec2);
		
		cout << endl;
	}
}