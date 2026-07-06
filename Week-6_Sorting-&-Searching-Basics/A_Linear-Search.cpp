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
	
	int x;
	cin >> x;
	
	bool found = false;
	 
	for(int i = 0; i < size; i++) {
		if(vec[i] == x) {
			found = true;
			break;
		}
	} 
	
	found ? cout << "YES" : cout << "NO";
}