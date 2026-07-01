#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

bool reverseSortComparator(int a, int b) {
	return a > b;
}

void reverseSort(vector<int>& vec) {
	sort(vec.begin(), vec.end(), reverseSortComparator);
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
	
	reverseSort(vec);
	
	for(const auto& val : vec) {
		cout << val << " ";
	}
}