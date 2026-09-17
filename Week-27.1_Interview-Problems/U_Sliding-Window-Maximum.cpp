#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

// Optimal Approach-> Uses Aggregated Queue (Two Stacks)
// T.C.-> O(N), S.C.-> O(N - K + 1) if storing in an array
class Queue {
private:
	stack<pair<int, int>> st1, st2;
public:
	void push(int val) {
		int max_val = val;
		if(!st1.empty()) {
			max_val = max(val, st1.top().second);
		}
		st1.push({val, max_val});
	}
	
	void pop() {
		if(st2.empty()) {
			while(!st1.empty()) {
				int max_val = st1.top().first;
				if(!st2.empty()) {
					max_val = max(max_val, st2.top().second);
				}
				st2.push({st1.top().first, max_val});
				st1.pop();
			}
		}
		st2.pop();
	}
	
	int getMax() {
		if(st1.empty()) return st2.top().second;
		else if(st2.empty()) return st1.top().second;
		else return max(st1.top().second, st2.top().second);
	}
};

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size, k;
	cin >> size >> k;
	
	vector<int> vec(size, 0);
	
	for(int i = 0; i < size; i++) {
		cin >> vec[i];
	}
	
	Queue que;
	vector<int> ans;
	
	for(int i = 0; i < size; i++) {
		que.push(vec[i]);
		
		if(i >= k - 1) {
			cout << que.getMax() << " ";
			que.pop();
		}
	}
}


// Optimal Approach-> Uses Deque
// T.C.-> O(N), S.C.-> O(N - K + 1) if storing in an array
/*
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size, k;
	cin >> size >> k;
	
	vector<int> vec(size, 0);
	
	for(int i = 0; i < size; i++) {
		cin >> vec[i];
	}
	
	vector<int> ans;
	
	deque<pair<int, int>> deq;
	
	for(int i = 0; i < k; i++) {
		while(!deq.empty() && deq.back().first <= vec[i]) {
			deq.pop_back();
		}
		deq.push_back({vec[i], i});
	}
	
	for(int i = k; i < size; i++) {
		cout << deq.front().first << " ";
		while(!deq.empty() && deq.back().first <= vec[i]) {
			deq.pop_back();
		}
		
		deq.push_back({vec[i], i});
		
		if(!deq.empty() && deq.front().second == i - k) deq.pop_front();
	}
	
	cout << deq.front().first;
}
*/



// Improved Approach-> Uses Priority Queue
// T.C.-> O(NlogK), S.C.-> O(N - K + 1) if storing in an array
/*
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size, k;
	cin >> size >> k;
	
	vector<int> vec(size, 0);
	
	for(int i = 0; i < size; i++) {
		cin >> vec[i];
	}
	
	vector<int> ans;
	

}
*/


// Brute Force Approach-> Check each k window separately
// T.C.-> O(N*K), S.C.-> O(N - K + 1) if storing in an array
/*
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size, k;
	cin >> size >> k;
	
	vector<int> vec(size, 0);
	
	for(int i = 0; i < size; i++) {
		cin >> vec[i];
	}
	
	vector<int> ans;
	
	for(int i = 0; i < size - k + 1; i++) {
		int max_val = INT_MIN;
		for(int j = i; j < i + k; j++) {
			max_val = max(vec[j], max_val);
		}
		cout << max_val << " ";
	}
}
*/