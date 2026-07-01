#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void subsequence(int index, int size, int arr[], vector<int> vec) {
	if(index == size) {
		for(const auto& val : vec) cout << val << " ";
		cout << endl;
		return;
	}
	
	subsequence(index + 1, size, arr, vec);
	
	vec.push_back(arr[index]);
	subsequence(index + 1, size, arr, vec);
	vec.pop_back();
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
	
	vector<int> vec;
	
	subsequence(0, size, arr, vec);
}