#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void reverse(vector<int>& vec) {
	int l = 0, r = vec.size() - 1;
	while(l < r) {
		int temp = vec[l];
		vec[l] = vec[r];
		vec[r] = temp;
		
		l++;
		r--;
	}
	
	for(int i = 0; i < vec.size(); i++) {
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