#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void pairSum(vector<int> vec, int sum) {
	int pair = 0;
	for(int i = 0; i < vec.size(); i++) {
		for(int j = i + 1; j < vec.size(); j++) {
			if(vec[i] + vec[j] == sum) pair++;
		}
	}
	
	cout << pair;
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
			int val;
			cin >> val;
			
			vec[i] = val;
		}
		
		int sum;
		cin >> sum;
		
		pairSum(vec, sum);
		
		cout << endl;
	}
}