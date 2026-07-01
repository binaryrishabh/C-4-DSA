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
	
	int ans = 0;
	
	for(int i = 0; i < 64; i++) {
		int bit = 0;
		for(int j = 0; j < size; j++) {
			int val = arr[j];
			
			bit += ((val >> i) & 1);
		}
		ans |= ((bit % 3) << i);
	}
	
	cout << ans;
}