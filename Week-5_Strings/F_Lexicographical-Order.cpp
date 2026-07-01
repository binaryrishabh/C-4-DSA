#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string a, b;
	cin >> a >> b;
	
	int i = 0;
	while(i < a.size() && i < b.size()) {
		if(a[i] < b[i]) {
			cout << "A";
			return 0;
		}
		else if(a[i] > b[i]) {
			cout << "B";
			return 0;
		}
		i++;
	}
	if(i < a.size()) {
		cout << "B";
		return 0;
	}
	if(i < b.size()) {
		cout << "A";
		return 0;
	}

	cout << "Equal";
}