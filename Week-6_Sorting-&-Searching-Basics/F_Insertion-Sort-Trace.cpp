#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void print(vector<int>& vec, int sorted) {
	for(int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	
	cout << ", ";
	
	
	for(int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
		if(i == sorted) cout << "| ";
	}
	
	cout << ", ";
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size;
	cin >> size;
	
	vector<int> vec(size, 0);
	
	for(int i = 0; i < size; i++) {
		cin >> vec[i];
	}
	
	// Standard — Sorted on Left, Pushes Leftward
	
	for(int i = 1; i < size; i++) {
		int shifts = 0;
		for(int j = i; j > 0; j--) {
	        if(vec[j - 1] > vec[j]) {
	            swap(vec[j - 1], vec[j]);
	        }
			else break;
			shifts++;
		}
		
		cout << "Pass " << i << ": ";
		print(vec, i);
		cout << "shifts = " << shifts << endl;
	}
	
	
	
	// Reverse — Sorted on Right, Pushes Rightward
	// But according to this question this code will not give 
	// correct shifts number for each iteration
	/*
	for(int i = size - 2; i >= 0; i--) {
		int shifts = 0;
	    for(int j = i; j < size - 1; j++) {
	        if(vec[j] > vec[j + 1]) {
	            swap(vec[j], vec[j + 1]);
	        }
			else break;
			shifts++;
		}
		
		cout << "Pass " << size - i - 1 << ": ";
		print(vec, size - i - 1);
		cout << "shifts = " << shifts << endl;
	}
	*/
}