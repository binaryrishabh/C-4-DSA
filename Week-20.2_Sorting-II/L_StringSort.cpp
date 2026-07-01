#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

bool customComparator(string str1, string str2) {
	if(str1.size() != str2.size()) {
		return str1.size() < str2.size();
	}
	
	return str1 < str2;
}

void stringSort(vector<string>& vec) {
	sort(vec.begin(), vec.end(), customComparator);
	
	for(const auto& val : vec) {
		cout << val << endl;
	}
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size;
	cin >> size;
	
	vector<string> vec(size, "");
	
	for(int i = 0; i < size; i++) {
		cin >> vec[i];
	}
	
	stringSort(vec);
}