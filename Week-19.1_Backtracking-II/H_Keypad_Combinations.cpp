#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void combinations(string path, int index, string s, string keypad[], vector<string>& vec) {
	if(index == s.size()) {
		vec.push_back(path);
		return;
	}
	
	int keypadIndex = s[index] - '0';
	string choice = keypad[keypadIndex];
	
	for(int i = 0; i < choice.size(); i++) {
		path += choice[i];
		combinations(path, index + 1, s, keypad, vec);
		path.pop_back();
	}
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	
	string keypad[10];
	keypad[2] = "abc";
	keypad[3] = "def";
	keypad[4] = "ghi";
	keypad[5] = "jkl";
	keypad[6] = "mno";
	keypad[7] = "pqrs";
	keypad[8] = "tuv";
	keypad[9] = "wxyz";
	
	vector<string> vec;
	
	combinations("", 0, s, keypad, vec);
	
	cout << vec.size() << endl;
	
	for(const auto& val : vec) cout << val << endl;
}