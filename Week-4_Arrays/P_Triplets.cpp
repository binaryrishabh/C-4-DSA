#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void triplets(vector<int>& vec, int x) {
	if(vec.size() < 3) {
		cout << 0;
		return;
	}
	
	int triplet = 0, size = vec.size();
	
	for(int i = 0; i < size - 2; i++) {
		int vali = vec[i];
		for(int j = i + 1; j < size - 1; j++) {
			int valj = vec[j];
			for(int k = j + 1; k < size; k++) {
				if(vali + valj + vec[k] == x) triplet++;
			}
		}
	}
	
	cout << triplet;
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int test;
	cin >> test;
	
	for(int t = 0; t < test; t++) {
		int size;
		cin >> size;
	
		vector<int> vec(size, 0);
		
		for(int i = 0; i < size; i++) {
			int val;
			cin >> val;
			
			vec[i] = val;
		}
		
		int x;
		cin >> x;

		triplets(vec, x);
		
		cout << endl;
	}
}