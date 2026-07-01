#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void combination(int index, int sum, int size, int target, int candidate[], vector<int> innerVec, vector<vector<int>>& outerVec) {
	if(index == size || sum > target) return;
	
	if(sum == target) {
		outerVec.push_back(innerVec);
		return;
	}
	
	innerVec.push_back(candidate[index]);
	combination(index, sum + candidate[index], size, target, candidate, innerVec, outerVec);
	innerVec.pop_back();
	
	combination(index + 1, sum, size, target, candidate, innerVec, outerVec);
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size, target;
	cin >> size >> target;
	
	int candidate[size];
	
	for(int i = 0; i < size; i++) {
		int val;
		cin >> val;
		
		candidate[i] = val;
	}
	
	vector<int> innerVec;
	vector<vector<int>> outerVec;
	
	combination(0, 0, size, target, candidate, innerVec, outerVec);
	
	cout << outerVec.size() << endl;
	for(vector<int> vec : outerVec) {
		cout << vec.size() << " ";
		for(const auto& val : vec) {
			cout << val << " ";
		}
		cout << endl;
	}
}