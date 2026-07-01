#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

	
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

// 1.
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int q;
	cin >> q;
	
	for(int i = 0; i < q; i++) {
		int x;
		cin >> x;
		
		
	}
}




//  2.
// ! Using arrays with Divisor-Sieve idea
// ! Optimal:- T.C. => O(max(x) * log(max(x)) + 2q), S.C. => O(max(x))
// signed main() {
// 	cin.tie(nullptr)->sync_with_stdio(false);
// 	int q;
// 	cin >> q;
	
// 	int query[q];
// 	int max_val = INT_MIN;
// 	for(int i = 0; i < q; i++) {
// 		int x;
// 		cin >> x;
		
// 		query[i] = x;
// 		max_val = max(max_val, x);
// 	}
	
// 	int factors[max_val];
// 	for(int i = 0; i <= max_val; i++) {
// 		factors[i] = 0;
// 	}
	
// 	for(int i = 1; i <= max_val; i++) {
// 		for(int j = i; j <= max_val; j += i) {
// 			factors[j]++;
// 		}
// 	}
	
// 	for(int i = 0; i < q; i++) {
// 		cout << factors[query[i]] << endl;
// 	}
// }




// 3.
// ! Using vectors with Divisor-Sieve idea
// ! More Improved:- T.C. => O(max(x) * log(max(x)) + 2q), S.C. => O(max(x) * log(max(x)))
// signed main() {
// 	cin.tie(nullptr)->sync_with_stdio(false);
// 	int q;
// 	cin >> q;
	
// 	int max_val = INT_MIN, query[q];
// 	for(int i = 0; i < q; i++) {
// 		int x;
// 		cin >> x;
		
// 		max_val = max(max_val, x);
// 		query[i] = x;
// 	}
	
// 	vector<int> vec[max_val + 1];
// 	for(int i = 1; i <= max_val; i++) {
// 		for(int j = i; j <= max_val; j += i) {
// 			vec[j].push_back(i);
// 		}
// 	}
	
// 	for(int i = 0; i < q; i++) {
// 		cout << vec[query[i]].size() << endl;
// 	}
// }




// 4.
// ! Using maps with Divisor-Sieve idea
// ! Improved:- T.C. => O(max(x) * log(max(x)) * log(max(x)) + 2q), S.C. => O(max(x))
// signed main() {
// 	cin.tie(nullptr)->sync_with_stdio(false);
// 	int q;
// 	cin >> q;
	
// 	map<int, int> map;
// 	int query[q], max_val = INT_MIN;
	
// 	for(int i = 0; i < q; i++) {
// 		int x;
// 		cin >> x;
		
// 		query[i] = x;
// 		max_val = max(max_val, x);
// 	}
	
// 	for(int i = 1; i <= max_val; i++) {
// 		for(int j = i; j <= max_val; j += i) {
// 			if(map.find(j) != map.end()) map[j]++;
// 			else map[j] = 1;
// 		}
// 	}
	
// 	for(int i = 0; i < q; i++) {
// 		cout << map[query[i]] << endl;
// 	}
// }





// 5.
// ! Using Square Root Method
// ! Better:- T.C. => O(q*sqrt(n)), S.C. => O(1)
// signed main() {
// 	cin.tie(nullptr)->sync_with_stdio(false);
// 	int q;
// 	cin >> q;
	
// 	for(int i = 0; i < q; i++) {
// 		int x;
// 		cin >> x;
		
// 		int divisor = 0;
// 		for(int j = 1; j * j <= x; j++) {
// 			if(x % j == 0) {
// 				if(j * j != x) divisor++;
// 				divisor++;
// 			}
// 		}
// 		cout << divisor << endl;
// 	}
// }




// 6.
// ! Worst/Brute:- T.C. => O(q*x), S.C. => O(1)
// signed main() {
// 	cin.tie(nullptr)->sync_with_stdio(false);
// 	int q;
// 	cin >> q;
	
// 	for(int i = 0; i < q; i++) {
// 		int x;
// 		cin >> x;
		
// 		int divisors = 0;
// 		for(int j = 1; j <= x; j++) {
// 			if(x % j == 0) divisors++;
// 		}
		
// 		cout << divisors << endl;
// 	}
// }