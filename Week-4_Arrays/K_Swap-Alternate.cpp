#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void alternate(int size) {
	vector<int> vec(size, 0);
	for(int i = 0; i < size; i++) {
		int val;
		cin >> val;
		
		vec[i] = val;
	}
	
	for(int i = 0; i + 1 < size; i += 2) {
		int temp = vec[i];
		vec[i] = vec[i + 1];
		vec[i + 1] = temp;
	}
	
	for(int i = 0; i < size; i++) {
		cout << vec[i] << " ";
	}
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int test;
	cin >> test;
	
	for(int t = 0; t < test; t++) {
		int size;
		cin >> size;
		
		alternate(size);
		
		cout << endl;
	}
}