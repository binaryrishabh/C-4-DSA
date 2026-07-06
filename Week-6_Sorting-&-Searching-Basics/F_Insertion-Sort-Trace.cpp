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
	
	for(int i = 0; i < size - 1; i++) {
		int shifts = 0;
		for(int j = i + 1; j > 0; j--) {
			if(vec[j] < vec[j - 1]) {
				int temp = vec[j];
				vec[j] = vec[j - 1];
				vec[j - 1] = temp;
			}
			else break;
			shifts++;
		}
		
		cout << "Pass " << i + 1 << ": ";
		print(vec, i + 1);
		cout << "shifts = " << shifts << endl;
	}
}