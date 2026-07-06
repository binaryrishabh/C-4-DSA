#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size;
	cin >> size;
	
	vector<string> vec(size, "");
	
	for(int i = 0; i < size; i++) {
		cin >> vec[i];
	}
	
	string str;
	cin >> str;
	
	int left = 0, right = size - 1;
	
	bool found = false;
	
	while(left <= right) {
		int mid = left + (right - left) / 2;
		
		if(vec[mid] < str) {
			left = mid + 1;
		}
		else if(vec[mid] > str) {
			right = mid - 1;
		}
		else {
			found = true;
			break;
		}
	}
	
	found ? cout << "YES" : cout << "NO";
}