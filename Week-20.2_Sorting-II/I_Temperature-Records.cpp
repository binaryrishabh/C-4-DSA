#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void temparatureRecord(vector<int> vec) {
	vector<int> freq(101, 0);
	
	for(const auto& val : vec) {
		freq[val + 50]++;
	}	
	
	for(int i = 0; i < 101; i++) {
		while(freq[i] > 0) {
			cout << i - 50 << " ";
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
	
	temparatureRecord(vec);
}