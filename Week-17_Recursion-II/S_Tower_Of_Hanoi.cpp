#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void hanoi(int n, string src, string aux, string dest) {
	if(n == 0) return;
	
	hanoi(n - 1, src, dest, aux);
	
	cout << "Move "<< src << " to " << dest << endl;
	
	hanoi(n - 1, aux, src, dest);
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	hanoi(n, "A", "B", "C");
}