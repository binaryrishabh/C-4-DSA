#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

// forward logic
int first_occurence_forward(int arr[], int i, int size, int x) {
	if(i == size) return -1;
	
	if(arr[i] == x) return i + 1;
	
	return first_occurence_forward(arr, i + 1, size, x);
}


// backward logic => slightly better.
int first_occurence_backward(int arr[], int i, int x) {
	if(i < 0) return -1;
	
	int index = -1;
	
	index = first_occurence_backward(arr, i - 1, x);
	
	if(arr[i] == x && index == -1) index = i + 1;
	
	return index;
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
	
	cout << first_occurence_forward(arr, 0, size, x);
	cout << first_occurence_backward(arr, size, x);
}