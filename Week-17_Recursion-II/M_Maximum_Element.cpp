#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int maximum(int arr[], int i) {
	if(i == 0) return arr[0];
	
	return max(arr[i], maximum(arr, i - 1));
}

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
	
	cout << maximum(arr, size - 1);
}