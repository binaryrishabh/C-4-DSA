#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	queue<int> que;
	
	que.push(1);
	que.push(2);
	
	int count = 0;
	
	while(count < n) {
		int num = que.front();
		que.pop();
		
		count++;
		
		if(count == n) {
			cout << num;
			break;
		}
		
		que.push((num * 10) + 1);
		que.push((num * 10) + 2);
	}	
}