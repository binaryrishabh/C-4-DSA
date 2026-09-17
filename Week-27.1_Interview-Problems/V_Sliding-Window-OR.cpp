#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'


// Optimal Approach-> Used Aggregated Queues (Two Stacks)
// T.C.-> O(N), S.C.-> O(K) for queue or O(N - K + 1) if storing in an array
class Queue {
private:
	stack<pair<int, int>> st1, st2;
public:
	void push(int val) {
		int OR = val;
		if(!st1.empty()) {
			OR |= st1.top().second;
		}
		st1.push({ val, OR });
	}
	
	void pop() {
		if(st2.empty()) {
			while(!st1.empty()) {
				int OR = st1.top().first;
				if(!st2.empty()) {
					OR |= st2.top().second;
				}
				st2.push({ st1.top().first, OR });
				st1.pop();
			}
		}
		st2.pop();
	}
	
	int getOR() {
		if(st1.empty()) return st2.top().second;
		else if(st2.empty()) return st1.top().second;
		else return st1.top().second | st2.top().second;
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
	
	for(int i = 0; i < size; i++) {
		que.push(vec[i]);
		
		if(i >= k - 1) {
			cout << que.getOR() << " ";
			que.pop();
		}
	}
}


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
	
	for(int i = 0; i < size - k + 1; i++) {
		int OR = 0;
		for(int j = i; j < i + k; j++) {
			OR |= vec[j];
		}
		cout << OR << " ";
	}
}
*/