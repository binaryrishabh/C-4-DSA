#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

// Optimal approach => T.C. -> O(N), S.C. -> O(K)
void largestNumber(vector<int>& vec) {
	vector<int> freq(10, 0);
	
	for(const auto& val : vec) {
		freq[val]++;
	}
	
	for(int i = 9; i >= 0; i--) {
		while(freq[i] > 0) {
			cout << i;
			freq[i]--;
		}
	}
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size;
	cin >> size;
	
	vector<int> vec(size);
	
	for(int i = 0; i < size; i++) {
		int val;
		cin >> val;
		
		vec[i] = val;
	}
	
	largestNumber(vec);
}