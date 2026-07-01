#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

// More Optimal:- T.C. => O(N*log(log(N))), S.C. => O(N)
// Sieve of Eratosthenes with square root method
void primes(int n) {
	vector<bool> isPrime(n + 1, true);

	for(int i = 2; i * i <= n; i++) {
		if(!isPrime[i]) continue;
		for(int j = i * i; j <= n; j += i) {
			isPrime[j] = false;
		}
	}
	
	for(int i = 2; i <= n; i++) {
		if(isPrime[i]) cout << i << " ";
	}
}


// Optimal:- T.C. => O(N*log(log(N))), S.C. => O(N)
// Sieve of Eratosthenes
// void primes(int n) {
// 	vector<bool> isPrime(n + 1, true);

// 	for(int i = 2; i <= n; i++) {
// 		if(!isPrime[i]) continue;
// 		for(int j = i * i; j <= n; j += i) {
// 			isPrime[j] = false;
// 		}
// 	}
	
// 	for(int i = 2; i <= n; i++) {
// 		if(isPrime[i]) cout << i << " ";
// 	}
// }



// More Improved:- T.C. => O(N*log(N)), S.C. => O(N)
// Divisor Count Sieve
// void primes(int n) {
// 	vector<int> vec(n + 1, 0);
	
// 	for(int i = 2; i <= n; i++) {
// 		for(int j = i; j <= n; j += i) {
// 			vec[j]++;
// 		}
// 	}
	
// 	for(int i = 0; i <= n; i++) {
// 		if(vec[i] == 1) cout << i << " ";
// 	}
// }



// Improved:- T.C. => O(N*sqrt(N)), S.C. => O(1)
// Square Root Method
// void primes(int n) {
// 	for(int i = 2; i <= n; i++) {
// 		bool isPrime = true;
// 		for(int j = 2; j * j <= i; j++) {
// 			if(i % j == 0) {
// 				isPrime = false;
// 				break;
// 			}
// 		}
// 		if(isPrime) cout << i << " ";
// 	}
// }



// Worst Approach:- T.C. => O(N^2), S.C. => O(1)
// void primes(int n) {
// 	for(int i = 2; i <= n; i++) {
// 		bool isPrime = true;
// 		for(int j = 2; j < i; j++) {
// 			if(i % j == 0) {
// 				isPrime = false;
// 				break;
// 			}
// 		}
// 		if(isPrime) cout << i << " ";
// 	}
// }

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	primes(n);
}