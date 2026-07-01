#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

// forward logic
void indices_forward(int arr[], int i, int size, int x, bool found) {
	if(i == size) {
		if(!found) cout << -1;
		return;
	}
	
	if(arr[i] == x) {
		cout << i + 1 << " ";
		found = true;
	}
	
	indices_forward(arr, i + 1, size, x, found);
}


/// backward logic
void indices_backward(int arr[], int i, int x, bool found) {
	if(i < 0) {
		if(!found) cout << -1;
		return;
	}
	
	if(arr[i] == x) found = true;

	
	indices_backward(arr, i - 1, x, found);
	
	if(arr[i] == x) {
		cout << i + 1 << " ";
	}
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
	
	int x;
	cin >> x;
	
	indices_forward(arr, 0, size, x, false);
	indices_backward(arr, size - 1, x, false);
}