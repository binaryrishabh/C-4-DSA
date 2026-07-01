#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void reversePrint(int arr[], int i) {
	if(i < 0) return;
	
	reversePrint(arr, i - 1);
	
	cout << arr[i] << " ";
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
	
	reversePrint(arr, size - 1);
}