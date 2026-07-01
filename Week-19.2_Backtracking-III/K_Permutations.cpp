#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

// 1.
// Optimal:- 
// Using a boolean found array which tracks which index of arr have been included or not.
void permutation(bool found[], int size, int arr[], vector<int> innerVec, vector<vector<int>>& outerVec) {
	if(innerVec.size() == size) {
		outerVec.push_back(innerVec);
		return;
	}
	
	for(int i = 0; i < size; i++) {
		int val = arr[i];
		
		if(!found[i]) {
			found[i] = true;
			innerVec.push_back(val);
			permutation(found, size, arr, innerVec, outerVec);
			innerVec.pop_back();
			found[i] = false;
		}
	}
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
	
	vector<int> innerVec;
	vector<vector<int>> outerVec;
	bool found[size];
	
	for(int i = 0; i < size; i++) found[i] = false;
	
	permutation(found, size, arr, innerVec, outerVec);
	
	cout << outerVec.size() << endl;
	
	for(vector<int> vec : outerVec) {
		for(const auto& val : vec) cout << val << " ";
		cout << endl;
	}		
}







// 2.
// Basic approach
// Check each time in the innerVec that the current index of the arr is present or not. So each time for loop runs.
// #include<bits/stdc++.h>
// using namespace std;

// #define int long long
// #define endl '\n'

// void permutation(int index, int size, int arr[], vector<int> innerVec, vector<vector<int>>& outerVec) {
// 	if(innerVec.size() == size) {
// 		outerVec.push_back(innerVec);
// 		return;
// 	}
	
// 	for(int i = 0; i < size; i++) {
// 		int val = arr[i];
// 		bool found = false;
// 		for(const auto& num : innerVec) {
// 			if(num == val) found = true;
// 		}
		
// 		if(!found) {
// 			innerVec.push_back(val);
// 			permutation(index, size, arr, innerVec, outerVec);
// 			innerVec.pop_back();
// 		}
// 	}
// }

// signed main() {
// 	cin.tie(nullptr)->sync_with_stdio(false);
// 	int size;
// 	cin >> size;
	
// 	int arr[size];
	
// 	for(int i = 0; i < size; i++) {
// 		int val;
// 		cin >> val;
// 		arr[i] = val;
// 	}
	
// 	vector<int> innerVec;
// 	vector<vector<int>> outerVec;
	
// 	permutation(0, size, arr, innerVec, outerVec);
	
// 	cout << outerVec.size() << endl;
	
// 	for(vector<int> vec : outerVec) {
// 		for(const auto& val : vec) cout << val << " ";
// 		cout << endl;
// 	}		
// }