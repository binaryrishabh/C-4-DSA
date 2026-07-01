#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

bool customComparator(string str1, string str2) {
	return str1 + str2 > str2 + str1;
}

void largestNumber(vector<string>& vec) {
	sort(vec.begin(), vec.end(), customComparator);
	
	string ans = "";
	for(string val : vec) {
		ans += val;
	}
	
	if(ans[0] - 48 == 0) {
		cout << 0;
		return;
	}
	
	cout << ans;
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size;
	cin >> size;
	
	vector<string> vec(size);
	
	for(int i = 0; i < size; i++) {
		int val;
		cin >> val;
		
		vec[i] = to_string(val);
	}
	
	largestNumber(vec);
}