#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size;
	cin >> size;
	
	int preVal;
	cin >> preVal;
	
	for(int i = 1; i < size; i++) {
		int currVal;
		cin >> currVal;
		
		if(preVal > currVal) {
			cout << "NO";
			return 0;
		}
		preVal = currVal;
	}
	
	cout << "YES";
}