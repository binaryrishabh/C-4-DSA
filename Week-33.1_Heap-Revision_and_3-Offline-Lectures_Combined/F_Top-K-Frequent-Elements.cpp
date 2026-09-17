#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'


// Optimal Approach - Using MaxHeap and map
// T.C.-> O(NlogK), S.C.-> O(K)

template<typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size, k;
	cin >> size >> k;
	
	unordered_map<int, int> map;
	
	for(int i = 0; i < size; i++) {
		int val;
		cin >> val;
		
		map[val]++;
	}
	
	MinHeap<pair<int, int>> pq;

    for(const auto& [first, second] : map) {
        pq.push({second, first});

        if(pq.size() > k) {
            pq.pop();
        }
    }

    vector<int> ans;
    while(!pq.empty()) {
        cout << pq.top().second << " ";
        pq.pop();
    }
}



// Approach - Using MaxHeap and map
// T.C.-> O(NlogN), S.C.-> O(N)
/*
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size, k;
	cin >> size >> k;
	
	unordered_map<int, int> map;
	
	for(int i = 0; i < size; i++) {
		int val;
		cin >> val;
		
		map[val]++;
	}
	
	priority_queue<pair<int, int>> pq;

    for(const auto& [first, second] : map) {
        pq.push({second, first});
    }

    vector<int> ans;
    while(k > 0) {
        cout << pq.top().second << " ";
        pq.pop();
        k--;
    }
}
*/


// Approach - Using MinHeap, Custom Comparator and map
// T.C.-> O(NlogK), S.C.-> O(N+K)
/*
template <typename T>
struct customComparator {
    bool operator()(const T& f, const T& s) {
        if(f.second != s.second) {
            return f.second > s.second;
        }

        return f.first > s.first;
    }
};

template <typename T>
using MinHeap = priority_queue<T, vector<T>, customComparator<T>>;

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size, k;
	cin >> size >> k;
	
	unordered_map<int, int> map;
	
	for(int i = 0; i < size; i++) {
		int val;
		cin >> val;
		
		map[val]++;
	}
	
	MinHeap<pair<int, int>> pq;

    for(const auto& [first, second] : map) {
        pq.push({first, second});

        if(pq.size() > k) {
            pq.pop();
        }
    }

    vector<int> ans;
    while(!pq.empty()) {
        cout << pq.top().first << " ";
        pq.pop();
    }
}
*/



// Approach - Using MaxHeap, Custom Comparator and map
// T.C.-> O(NlogN), S.C.-> O(N)
/*
template <typename T>
struct customComparator {
    bool operator()(const T& f, const T& s) {
        if(f.second != s.second) {
            return f.second < s.second;
        }

        return f.first < s.first;
    }
};

template <typename T>
using MaxHeap = priority_queue<T, vector<T>, customComparator<T>>;

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size, k;
	cin >> size >> k;
	
	unordered_map<int, int> map;
	
	for(int i = 0; i < size; i++) {
		int val;
		cin >> val;
		
		map[val]++;
	}
	
	MaxHeap<pair<int, int>> pq;

    for(const auto& [first, second] : map) {
        pq.push({first, second});
    }

    vector<int> ans;
    while(k > 0) {
        cout << pq.top().first << " ";
        pq.pop();
        k--;
    }
}
*/


// Simplest Approach - Sorting using vector and map
// T.C.-> O(NlogN), S.C.-> O(N)
/*
static bool customComparator(pair<int, int> f, pair<int, int> s) {
    if(f.second != s.second) {
        return f.second > s.second;
    }

    return f.first > s.first;
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size, k;
	cin >> size >> k;
	
	unordered_map<int, int> map;
	
	for(int i = 0; i < size; i++) {
		int val;
		cin >> val;
		
		map[val]++;
	}

    vector<pair<int, int>> vec;

    for(const auto& [first, second] : map) {
        vec.push_back({first, second});
    }

    sort(vec.begin(), vec.end(), customComparator);

    vector<int> ans;

    for(int i = 0; i < k; i++) {
        cout << vec[i].first << " ";
    }
}
*/