#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void reverse(vector<int> vec) {
	for(int i = vec.size() - 1; i >= 0; i--) {
		cout << vec[i] << " ";
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
	
	reverse(vec);
}