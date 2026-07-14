#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	cout << "Discarded cards: ";
	
	queue<int> que;
	
	for(int i = 1; i <= n; i++) {
		que.push(i);
	}
	
	while(que.size() > 1) {
		int value = que.front();
		cout << value << " ";
		que.pop();
		
		if(que.size() > 1) {
			value = que.front();
			que.push(value);
			que.pop();
		}
	}
	
	cout << endl << "Remaining card: " << que.front();;
	
	cout << endl;
}