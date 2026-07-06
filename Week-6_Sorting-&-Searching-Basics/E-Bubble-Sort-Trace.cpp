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
	
	for(int i = 0; i < size - 1; i++) {
		bool swap = false;
		int swaps = 0;
		for(int j = 1; j < size - i; j++) {
			if(vec[j] < vec[j - 1]) {
				swap = true;
				swaps++;
				int temp = vec[j];
				vec[j] = vec[j - 1];
				vec[j - 1] = temp;
			}
		}
		cout << "Pass " << i + 1 << ": ";
		for(int i = 0; i < size; i++) {
			cout << vec[i] << " ";
		}
		cout << ", swaps = " << swaps << endl;
		
		if(!swap) break;
	}
}