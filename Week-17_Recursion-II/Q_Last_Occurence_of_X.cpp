#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'


// forward logic
int last_occurence_forward(int arr[], int i, int size, int x) {
	if(i == size) return -1;
	
	int index = last_occurence_forward(arr, i + 1, size, x);
	
	if(arr[i] == x && index == -1) return i + 1;
	
	return index;
}

// backward logic
int last_occurence_backward(int arr[], int i, int x) {
	if(i < 0) return -1;
	
	if(arr[i] == x) return i + 1;
	
	return last_occurence_backward(arr, i - 1, x);
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
	
	cout << last_occurence_forward(arr, 0, size, x);
	cout << last_occurence_backward(arr, size - 1, x);
}