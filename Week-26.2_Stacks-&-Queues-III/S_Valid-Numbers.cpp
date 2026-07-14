#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	vector<int> vec(10, 0);
	
	for(int i = 0; i < 10; i++) {
		cin >> vec[i];
	}
	
	int n;
	cin >> n;
	
	queue<string> que;
	int count = 0;
	
	while(count < n) {
		string str = "";
		if(!que.empty()) {
			str = que.front();
			cout << str << endl;
			que.pop();
			count++;
		}
		
		if(count == n) {
			break;
		}
		
		for(int i = 0; i < 10; i++) {
			if(str.empty() && i == 0 && vec[0] == 1) continue;
			if(vec[i] == 1) {
				que.push(str + to_string(i));
			}
		}
	}
}