#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int sum(vector<int>& vec, int index) {
	if(index == vec.size()) {
		return 0;
	}
	return vec[index] + sum(vec, index + 1);
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int size;
	cin >> size;
	
	vector<int> vec(size, 0);
	
	for(int i = 0; i < size; i++) {
		cin >> vec[i];
	}
	
	cout << sum(vec, 0);
}