#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size;
	cin >> size;
	
	vector<int> vec(size, 0);
	
	for(int i = 0; i < size; i++) {
		cin >> vec[i];
	}
	
	// Standard — Sorted on Right, Sweeps Left-to-Right
	
	for(int i = size - 1; i > 0; i--) {
		int swaps = 0;
		for(int j = 0; j < i; j++) {
	        if(vec[j] > vec[j + 1]) {
	            swap(vec[j], vec[j + 1]);
				swaps++;
	        }
		}
		cout << "Pass " << i + 1 << ": ";
		for(int i = 0; i < size; i++) {
			cout << vec[i] << " ";
		}
		cout << ", swaps = " << swaps << endl;
		
		if(swaps == 0) break;
	}
	
	
	// Reverse — Sorted on Left, Sweeps Right-to-Left
	// But according to this question this code will not give 
	// correct shifts number for each iteration
	/*
	for(int i = 0; i < size - 1; i++) {
		int swaps = 0;
		for(int j = size - 1; j > i; j--) {
	        if(vec[j - 1] > vec[j]) {
				swaps++;
	            swap(vec[j - 1], vec[j]);
	        }
		}
		cout << "Pass " << i + 1 << ": ";
		for(int i = 0; i < size; i++) {
			cout << vec[i] << " ";
		}
		cout << ", swaps = " << swaps << endl;
		
		if(swaps == 0) break;
	}
	*/
}