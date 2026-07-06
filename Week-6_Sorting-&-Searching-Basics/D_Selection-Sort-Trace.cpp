#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void print(vector<int>& vec) {
	for(int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
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
	
	for(int i = 0; i < size - 1; i++) {
		int min = vec[i], index = i;
		for(int j = i; j < size; j++) {
			if(min > vec[j]) {
				min = vec[j];
				index = j;
			}
		}
		
		int temp = vec[i];
		vec[i] = vec[index];
		vec[index] = temp;
		
		cout << "Pass " << i + 1 << ": ";
		print(vec);
		cout << "min_selected = " << min << endl;
	}
}