#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string str;
	cin >> str;
	
	int twoPowerTaken = 1, decimal = 0, index = str.size() - 1;
	
	while(index >= 0) {
		if(str[index] == '1') decimal += twoPowerTaken;
			
		twoPowerTaken *= 2;
			
		index--;
	}
	
	cout << decimal;
}