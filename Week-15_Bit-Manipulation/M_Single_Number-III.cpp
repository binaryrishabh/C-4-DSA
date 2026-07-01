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
	
	int XOR = 0;
	for(int i = 0; i < size; i++) {
		XOR ^= arr[i];
	}
	
	int index = 0;
	while((XOR & 1) != 1) {
		index++;
		XOR >>= 1;
	}
	
	int group1 = 0; // The numbers having index bit as 0.
	int group2 = 0; // The numbers having index bit as 1.	
	
	for(int i = 0; i < size; i++) {
		int val = arr[i];
		
		if(((val >> index) & 1) == 0) group1 ^= val;
		else group2 ^= val;
	}
	
	if(group1 < group2) cout << group1 << " " << group2;
	else cout << group2 << " " << group1;
}