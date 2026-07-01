#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void quadriplet(vector<int> vec, int x) {
	if(vec.size() < 4) {
		cout << 0;
		return;
	}
	
	int quad = 0, size = vec.size();
	
	for(int i = 0; i < size - 3; i++) {
		int vali = vec[i];
		for(int j = i + 1; j < size - 2; j++) {
			int valj = vec[j];
			for(int k = j + 1; k < size - 1; k++) {
				int valk = vec[k];
				for(int l = k + 1; l < size; l++) {
					if(vali - (2 * valj) + (3 * valk) - (4 * vec[l]) == x) quad++;
				}
			}
		}
	}
	
	cout << quad;
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int size, x;
	cin >> size >> x;

	vector<int> vec(size, 0);
	
	for(int i = 0; i < size; i++) {
		int val;
		cin >> val;
		
		vec[i] = val;
	}
	
	quadriplet(vec, x);
}