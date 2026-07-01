#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int length, breadth;
	cin >> length >> breadth;
	
	cout << "Area = " << length * breadth << endl;
	cout << "Perimeter = " << 2 * (length + breadth) << endl;
}