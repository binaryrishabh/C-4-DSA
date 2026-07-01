#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void encoding(string encode, int index, string s, vector<string>& vec) {
	if(index > s.length()) return;
	if(index == s.length()) {
		vec.push_back(encode);
		return;
	}

	string curr = "";
	int num = 0;
	char ch;
	
	// Taking 1 caharcters at a time.
	curr = s[index];
	num = stoi(curr);
	if(num == 0) return;
	ch = (char)(num + 96);
	encode.push_back(ch);
	encoding(encode, index + 1, s, vec);
	encode.pop_back();
	
	// Taking 2 caharcters at a time.
	curr = s[index];
	curr += s[index + 1];
	num = stoi(curr);
	if(num <= 26) {
		ch = (char)(num + 96);
		encode.push_back(ch);
		encoding(encode, index + 2, s, vec);
		encode.pop_back();
	}
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
		
	vector<string> vec;
	
	encoding("", 0, s, vec);
	
	cout << vec.size() << endl;
	
	for(const auto& val : vec) cout << val << endl;
}