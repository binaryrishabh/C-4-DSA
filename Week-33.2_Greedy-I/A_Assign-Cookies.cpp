#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

// Approach:- Greedy
// T.C.-> O(NlogN + MlogM + M), S.C.-> O(logN + logM)
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n;
	
	vector<int> stud(n, 0);
	
	for(int i = 0; i < n; i++) {
		cin >> stud[i];
	}
	
	cin >> m;
	
	vector<int> cookies(m, 0);
	
	for(int i = 0; i < m; i++) {
		cin >> cookies[i];
	}
	
	sort(stud.begin(), stud.end());
	sort(cookies.begin(), cookies.end());
	
	int i = 0, j = 0;
	
	while(i < m && j < n) {
		if(cookies[i] >= stud[j]) {
			j++;
		}
		i++;
	}
	
	cout << j;
}