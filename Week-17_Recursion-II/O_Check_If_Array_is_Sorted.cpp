#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

check_sorted(int arr[], int i) {
	if(i == 0) return true;
	
	return check_sorted(arr, i - 1) && arr[i] >= arr[i - 1];
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
	
	check_sorted(arr, size - 1) ? cout << "YES" : cout << "NO";
}