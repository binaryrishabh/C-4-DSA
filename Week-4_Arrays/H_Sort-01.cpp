#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'


// Optimal => T.C. -> O(N), S.C. -> O(1)
// Two Pointers approach (One Pass Approach)
void sort(int size) {
	vector<int> vec(size, 0);
	
	for(int i = 0; i < size; i++) {
		int val;
		cin >> val;
		
		vec[i] = val;
	}
	
	int i = 0, j = size - 1;
	while(i <= j) {
		while(vec[i] == 0) i++;
		while(vec[j] == 1) j--;
		if(i <= j) {
			int temp = vec[i];
			vec[i] = vec[j];
			vec[j] = temp;
		}
	}
	
	for(int i = 0; i < size; i++) {
		cout << vec[i] << " ";
	}
}



// Brute Force => T.C. -> O(N), S.C. -> O(1)
// Counting approach (Two Pass Approach)
// void sort(int size) {
// 	int zero = 0;
	
// 	for(int i = 0; i < size; i++) {
// 		int val;
// 		cin >> val;
		
// 		if(val == 0) zero++;
// 	}
	
// 	for(int i = 0; i < zero; i++) {
// 		cout << 0 << " ";
// 	}
	
// 	for(int i = 0; i < size - zero; i++) {
// 		cout << 1 << " ";
// 	}
// }

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int test;
	cin >> test;
	
	for(int t = 0; t < test; t++) {
		int size;
		cin >> size;
		
		sort(size);
		
		cout << endl;
	}
}