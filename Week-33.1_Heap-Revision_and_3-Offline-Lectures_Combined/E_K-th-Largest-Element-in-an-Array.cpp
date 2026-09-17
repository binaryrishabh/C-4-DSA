#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'


// Approach - Max-Heap
// T.C.-> O(N), S.C.-> O(K)
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size, k;
	cin >> size >> k;
	
	priority_queue<int, vector<int>, greater<int>> pq;
	
	for(int i = 0; i < size; i++) {
		int val;
		cin >> val;
		
		pq.push(val);
		
		if(pq.size() > k) {
			pq.pop();
		}
	}
	
	cout << pq.top();
}


// Approach - Max-Heap
// T.C.-> O(N), S.C.-> O(N)
/*
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size, k;
	cin >> size >> k;
	
	priority_queue<int> pq;
	
	for(int i = 0; i < size; i++) {
		int val;
		cin >> val;
		
		pq.push(val);
	}
	
	while(k > 1) {
		pq.pop();
		k--;
	}
	
	cout << pq.top();
}
*/


// Approach - Sorting
// T.C.-> O(NlogN), S.C.-> O(logN)
/*
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size, k;
	cin >> size >> k;
	
	vector<int> vec(size, 0);
	
	for(int i = 0; i < size; i++) {
		cin >> vec[i];
	}
	
	sort(vec.begin(), vec.end());
	
	cout << vec[vec.size() - k];
}
*/