#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

// Approach:- Greedy, Fractional Knapsack
// T.C.-> O(NlogN), S.C.-> O(logN)
struct knap {
	int val;
	int wei;
};

bool customComparator(knap& first, knap& second) {
	return first.val * second.wei > second.val * first.wei;
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size, cap;
	cin >> size >> cap;
	
	vector<knap> vec(size);
	
	for(int i = 0; i < size; i++) {
		cin >> vec[i].val >> vec[i].wei;
	}
	
	sort(vec.begin(), vec.end(), customComparator);
	
	int i = 0;
	double total = 0;
	while(cap > 0 && i < size) {
		if(vec[i].wei <= cap) {
			total += vec[i].val;
			cap -= vec[i].wei;
		}
		else {
			total += ((double)(vec[i].val) / vec[i].wei) * cap;
			cap = 0;
		}
		i++;
	}
	
	cout << fixed << setprecision(6) << total;
}