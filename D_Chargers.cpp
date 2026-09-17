#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int query, v;
	cin >> query >> v;
	
	priority_queue<int> pq;
	
	for(int i = 0; i < query; i++) {
		int type, t, w;
		cin >> type >> t;
		if(type == 1) {
			cin >> w;
			pq.push(w - t);
		}
		else {
			if(pq.empty()) {
				cout << -1;
			}
			else {
				int currMaxCharge = pq.top();
				pq.pop();
				int charge = min(v, currMaxCharge + t);
				cout << charge;
			}
			cout << endl;
		}
	}
}