// Q. Sort the array which only has values 0 and 1.
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

// Optimal:- Two Pointers. T.C. -> O(N), S.C. -> O(1)
// Known as ONE PASS APPROACH
void sorting(vector<int>& vec) {
	int i = 0, j = vec.size() - 1;
	
	while(i < j) {
		if(vec[i] == 1) {
			int temp = vec[i];
			vec[i] = vec[j];
			vec[j] = temp;
			j--;
		}
		else {
			i++;
		}
	}
}

// Better:- Count sort. T.C. -> O(N), S.C. -> O(1)
// Known as TWO PASS APPROACH
// void sorting(vector<int>& vec) {
// 	int zero = 0;
	
// 	for(int val : vec) {
// 		if(val == 0) zero++;
// 	}
	
// 	for(int i = 0; i < vec.size(); i++) {
// 		if(zero > 0) {
// 			vec[i] = 0;
// 			zero--;
// 		}
// 		else {
// 			vec[i] = 1;
// 		}
// 	}
// }



// Worst:- Using Inbuilt sort. T.C. -> O(NlogN), S.C. -> O(logN)
// void sorting(vector<int>& vec) {
// 	sort(vec.begin(), vec.end());
// }

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size;
	cin >> size;
	
	vector<int> vec(size, 0);
	
	for(int i = 0; i < size; i++) {
		cin >> vec[i];
	}
	
	sorting(vec);
	
	for(const auto& val : vec) {
		cout << val << " ";
	}
}