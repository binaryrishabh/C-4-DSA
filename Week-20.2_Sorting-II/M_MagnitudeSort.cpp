#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

bool customComparator(int a, int b) {
	int aAbsolute = abs(a), bAbsolute = abs(b);
	
	if(aAbsolute == bAbsolute) {
		return a < b;
	}
	
	return aAbsolute < bAbsolute;
}

void magnitudeSort(vector<int> vec) {
	sort(vec.begin(), vec.end(), customComparator);
	
	for(const auto& val : vec) {
		cout << val << " ";
	}
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size;
	cin >> size;
	
	vector<int> vec(size, 0);
	
	for(int i = 0; i < size; i++) {
		int val;
		cin >> val;
		
		vec[i] = val;
	}
	
	magnitudeSort(vec);
}