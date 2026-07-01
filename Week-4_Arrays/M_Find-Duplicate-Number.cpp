#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void duplicate(vector<int> vec) {
	vector<int> freq(1001, 0);
	
	for(const auto& val : vec) {
		if(freq[val] == 1) {
			cout << val;
			return;
		}
		freq[val]++;
	}
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int test;
	cin >> test;
	
	for(int t = 0; t < test; t++) {
		int size;
		cin >> size;
		
		vector<int> vec(size);
		for(int i = 0; i < size; i++) {
			int val;
			cin >> val;
			
			vec[i] = val;
		}
		
		duplicate(vec);
		
		cout << endl;
	}
}