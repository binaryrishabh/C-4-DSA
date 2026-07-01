#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

// 1.


// 2.
// ! Using Sieve of Eratosthenes with Square Root Method
// ! More Optimal :- T.C. => O(size + max_val + n*log(log(n)) + size), S.C. => O(max_val).
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size;
	cin >> size;
	
	int query[size], max_val = INT_MIN;
	
	for(int i = 0; i < size; i++) {
		int val;
		cin >> val;
		
		query[i] = val;
		max_val = max(max_val, val);
	}
	
	bool isPrime[max_val + 1];
	isPrime[0] = false;
	isPrime[1] = false;
	for(int i = 2; i <= max_val; i++) {
		isPrime[i] = true;
	}
	
	for(int i = 2; i * i <= max_val; i++) {
		if(isPrime[i]) {
			for(int j = i * i; j <= max_val; j += i) {
				isPrime[j] = false;
			}
		}
	}
	
	for(int i = 0; i < size; i++) {
		if(isPrime[query[i]]) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}


// 3.
// ! Using Sieve of Eratosthenes
// ! Optimal:- T.C. => O(size + max_val + n*log(log(n)) + size), S.C. => O(max_val).
// signed main() {
// 	cin.tie(nullptr)->sync_with_stdio(false);
// 	int size;
// 	cin >> size;
	
// 	int query[size], max_val = INT_MIN;
	
// 	for(int i = 0; i < size; i++) {
// 		int val;
// 		cin >> val;
		
// 		query[i] = val;
// 		max_val = max(max_val, val);
// 	}
	
// 	bool isPrime[max_val + 1];
// 	isPrime[0] = false;
// 	isPrime[1] = false;
// 	for(int i = 2; i <= max_val; i++) {
// 		isPrime[i] = true;
// 	}
	
// 	for(int i = 2; i <= max_val; i++) {
// 		if(isPrime[i]) {
// 			for(int j = i * 2; j <= max_val; j += i) {
// 				isPrime[j] = false;
// 			}
// 		}
// 	}
	
// 	for(int i = 0; i < size; i++) {
// 		if(isPrime[query[i]]) cout << "YES";
// 		else cout << "NO";
// 		cout << endl;
// 	}
// }


// 4.
// ! Using Arrays with Divisor-Sieve idea
// ! Improved:- T.C. => O(size + max_val + max_val*log(max_val) + size), S.C. => O(size + max_val).
// signed main() {
// 	cin.tie(nullptr)->sync_with_stdio(false);
// 	int size;
// 	cin >> size;
	
// 	int query[size], max_val = INT_MIN;
	
// 	for(int i = 0; i < size; i++) {
// 		int val;
// 		cin >> val;
		
// 		query[i] = val;
// 		max_val = max(max_val, val);
// 	}
	
// 	int isPrime[max_val + 1];
// 	for(int i = 0; i <= max_val; i++) isPrime[i] = 0;
		
// 	for(int i = 1; i <= max_val; i++) {
// 		for(int j = i; j <= max_val; j += i) {
// 			isPrime[j]++;
// 		}
// 	}
	
// 	for(int i = 0; i < size; i++) {
// 		if(isPrime[query[i]] == 2) cout << "YES";
// 		else cout << "NO";
// 		cout << endl;
// 	}
// }




// 5.
// ! Using Square Root Method
// ! Better:- T.C. => O(size + max_val + max_val*sqrt(max_val) + size), S.C. => O(size + max_val).
// signed main() {
// 	cin.tie(nullptr)->sync_with_stdio(false);
// 	int size;
// 	cin >> size;
	
// 	int query[size];
// 	int max_val = INT_MIN;
// 	for(int i = 0; i < size; i++) {
// 		int val;
// 		cin >> val;
		
// 		query[i] = val;
// 		max_val = max(max_val, val);
// 	}
	
// 	bool isPrime[max_val + 1];
// 	isPrime[0] = false;
// 	isPrime[1] = false;
// 	for(int i = 2; i <= max_val; i++) {
// 		isPrime[i] = true;
// 	}
	
// 	for(int i = 2; i <= max_val; i++) {
// 		bool divided = false;
// 		for(int j = 2; j * j <= i; j++) {
// 			if(i % j == 0) {
// 				divided = true;
// 				break;
// 			}
// 		}
// 		if(divided) isPrime[i] = false;
// 	}
	
// 	for(int i = 0; i < size; i++) {
// 		if(isPrime[query[i]]) cout << "YES";
// 		else cout << "NO";
		
// 		cout << endl;
// 	}
// }


// 6.
// ! Brute/Worst:- T.C. => O(size  + max_val + max_val^2 + size), S.C. => O(size + max_val).
// signed main() {
// 	cin.tie(nullptr)->sync_with_stdio(false);
// 	int size;
// 	cin >> size;
	
// 	int query[size];
// 	int max_val = INT_MIN;
// 	for(int i = 0; i < size; i++) {
// 		int val;
// 		cin >> val;
		
// 		query[i] = val;
// 		max_val = max(max_val, val);
// 	}
	
// 	bool isPrime[max_val + 1];
// 	isPrime[0] = false;
// 	isPrime[1] = false;
// 	for(int i = 2; i <= max_val; i++) {
// 		isPrime[i] = true;
// 	}
	
// 	for(int i = 2; i <= max_val; i++) {
// 		bool divided = false;
// 		for(int j = 2; j < i; j++) {
// 			if(i % j == 0) {
// 				divided = true;
// 				break;
// 			}
// 		}
// 		if(divided) isPrime[i] = false;
// 	}
	
// 	for(int i = 0; i < size; i++) {
// 		if(isPrime[query[i]]) cout << "YES";
// 		else cout << "NO";
		
// 		cout << endl;
// 	}
// }