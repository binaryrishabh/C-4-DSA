#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

// 1.

// 1.
// ! Using Divisor-Sieve idea
// ! Optimal:- T.C. => O(N*log(N) + N*log(N)); S.C. => O(N*log(N));
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	vector<int> vec[n + 1];
	
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j += i) vec[j].push_back(i);
	}

	for(int i = 1; i <= n; i++) {
		for(const auto& val : vec[i]) {
			cout << val << " ";
		}
		cout << endl;
	}
}

// 2.
// ! Using Square Root Method
// ! Improved:- T.C. => O(N*sqrt(N)); S.C. => O(1);
// signed main() {
// 	cin.tie(nullptr)->sync_with_stdio(false);
// 	int n;
// 	cin >> n;
	
// 	int fact = 1;
// 	for(int i = 1; i <= n; i++) {
// 		for(fact = 1; fact * fact <= i; fact++) {
// 			if(i % fact == 0) cout << fact << " ";
// 		}
// 		for(fact = fact - 1; fact >= 1; fact--) {
// 			if(i % fact == 0) {
// 				if(fact * fact != i) cout << i / fact << " ";
// 			}
// 		}
// 		cout << endl;
// 	}
// }

// 3.
// ! Brute/Worst:- T.C. => O(N^2); S.C. => O(1)
// signed main() {
// 	cin.tie(nullptr)->sync_with_stdio(false);
// 	int n;
// 	cin >> n;
	
// 	for(int num = 1; num <= n; num++) {
// 		for(int fact = 1; fact <= num; fact++) {
// 			if(num % fact == 0) cout << fact << " ";
// 		}
// 		cout << endl;
// 	}
// }