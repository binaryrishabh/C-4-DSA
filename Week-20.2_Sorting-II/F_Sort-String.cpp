#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void sortString(string str) {
	vector<int> freq(26, 0);
	
	for(char ch : str) {
		freq[ch - 97]++;
	}
	
	for(int i = 0; i < 26; i++) {
		while(freq[i] > 0) {
			cout << (char)(i + 97);
			freq[i]--;
		}
	}
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	
	sortString(s);
}