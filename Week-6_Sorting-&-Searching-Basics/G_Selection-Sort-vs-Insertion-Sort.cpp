#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int insertionSort(vector<int> vec) {
	int shifts = 0;
	for(int i = 1; i < vec.size(); i++) {
		for(int j = i; j > 0; j--) {
			if(vec[j] < vec[j - 1]) {
				swap(vec[j], vec[j - 1]);
				shifts++;
			}
			else break;
		}
	}
	
	return shifts;
}

int selectionSort(vector<int> vec) {
	int swaps = 0;
	
	for(int i = 0; i < vec.size() - 1; i++) {
		int min_element = vec[i], index = i;
		for(int j = i + 1; j < vec.size(); j++) {
			if(min_element > vec[j]) {
				min_element = vec[j];
				index = j;
			}
		}
		
		if(index != i) {
			vec[index] = vec[i];
			vec[i] = min_element;
			swaps++;
		}
	}
	
	return swaps;
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int test;
	cin >> test;
	
	for(int t = 0; t < test; t++) {
		int size;
		cin >> size;
		
		vector<int> vec(size, 0);
		
		for(int i = 0; i < size; i++) {
			cin >> vec[i];
		}
		
		
		int shifts = insertionSort(vec);
		
		int swaps = selectionSort(vec);
		
		if(shifts < swaps) {
			cout << "Insertion Sort";
		}
		else if(shifts > swaps) {
			cout << "Selection Sort";
		}
		else {
			cout << "Tie";
		}
		
		cout << endl;
	}
}