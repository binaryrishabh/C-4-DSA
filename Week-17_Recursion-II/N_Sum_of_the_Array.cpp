#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int sum(int arr[], int i) {
	if(i == 0) return arr[i];
	
	return arr[i] + sum(arr, i - 1);
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
	
	cout << sum(arr, size - 1);
}