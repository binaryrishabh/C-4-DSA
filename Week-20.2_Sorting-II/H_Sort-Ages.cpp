#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void sortAges(vector<int> vec) {
	vector<int> freq(101, 0);
	
	for(const auto& val : vec) {
		freq[val]++;
	}
	
	for(int i = 0; i < 101; i++) {
		while(freq[i] > 0) {
			cout << i << " ";
			freq[i]--;
		}
	}
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size;
	cin >> size;
	
	vector<int> vec(size, 0);
	
	for(int i = 0; i < size; i++) {
		int val;
		cin >> val;
		
		vec[i] = val;
	}
	
	sortAges(vec);
}