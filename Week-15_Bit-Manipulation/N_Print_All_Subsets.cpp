#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size;
	cin >> size;
	
	int arr[size];
	
	for(int i = 0; i < size; i++) {
		int val;
		cin >> val;
		
		arr[i] = val;
	}
	
	for(int i = 1; i <= (1 << size); i++) {
		int bit = i;
		for(int j = 0; j < size; j++) {
			if((bit & 1) == 1) cout << arr[j] << " ";
			bit >>= 1;
		}
		cout << endl;
	}
}