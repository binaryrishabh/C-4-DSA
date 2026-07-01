#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void arrange(int size) {
	vector<int> vec(size, 0);

	int i = 0, j = size - 1, val = 1;
	while(i < j) {
		vec[i++] = val++;
		vec[j--] = val++;
	}
	
	if(i == j) vec[i] = val;
	
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
		
		arrange(size);
		
		cout << endl;
	}
}