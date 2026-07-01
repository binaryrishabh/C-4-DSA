#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

// 1.
// ! 



// 2.
// ! Using Sieve of Eratosthenes with Square Root Method
// ! More Optimal :- T.C. => O(n*log(log(n))), S.C. => O(n).
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	bool isPrime[n + 1];
	
	for(int i = 2; i <= n; i++) {
		isPrime[i] = true;
	}
	
	for(int i = 2; i * i <= n; i++) { // More optimized
		if(isPrime[i]) {
			for(int j = i * i; j <= n; j += i) { // More optimized
				isPrime[j] = false;
			}
		}
	}
	
	int primes = 0;
	for(int i = 2; i <= n; i++) {
		if(isPrime[i]) {
			// cout << i << " ";
			primes++;
		}
	}
	
	cout << endl << primes;
}




// 3.
// ! Using Sieve of Eratosthenes
// ! Optimal:- T.C. => O(n*log(log(n)) + 2*n), S.C. => O(n).
// signed main() {
// 	cin.tie(nullptr)->sync_with_stdio(false);
// 	int n;
// 	cin >> n;

// 	bool isPrime[n + 1];
	
// 	for(int i = 0; i <= n; i++) {
// 		isPrime[i] = true;
// 	}
		
// 	for(int i = 2; i <= n; i++) {
// 		if(isPrime[i]) {
// 			for(int j = 2 * i; j <= n; j += i) {
// 				isPrime[j] = false;
// 			}
// 		}
// 	}
	
// 	int count = 0;
// 	for(int i = 2; i <= n; i++) {
// 		if(isPrime[i]) {
// 			cout << i << " ";
// 			count++;
// 		}
// 	}
	
// 	cout << endl << count;
// }




// 4.
// ! Using Arrays with Divisor-Sieve idea
// ! Improved:- T.C. => O(n*log(n)), S.C. => O(n).
// signed main() {
// 	cin.tie(nullptr)->sync_with_stdio(false);
// 	int n;
// 	cin >> n;
	
// 	int factors[n + 1];
	
// 	for(int i = 0; i <= n; i++) factors[i] = 0;
	
// 	for(int i = 1; i <= n; i++) {
// 		for(int j = i; j <= n; j += i) {
// 			factors[j]++;
// 		}
// 	}
	
// 	int prime = 0;
// 	for(int i = 0; i <= n; i++) {
// 		if(factors[i] == 2) {
// 			prime++;
// 			cout << i << " ";
// 		}
// 	}
	
// 	cout << endl << prime;
// }



// 5.
// ! Using Square Root Method
// ! Better:- T.C. => O(n*sqrt(n)), S.C. => O(1).
// signed main() {
// 	cin.tie(nullptr)->sync_with_stdio(false);
// 	int n;
// 	cin >> n;
	
// 	int prime = 0;
// 	for(int i = 2; i <= n; i++) {
// 		bool divided = false;
// 		for(int j = 2; j * j <= i; j++) {
// 			if(i % j == 0) {
// 				divided = true;
// 				break;
// 			}
// 		}
// 		if(!divided) {
// 			cout << i << " ";
// 			prime++;
// 		}
// 	}
// 	cout << endl << prime;
// }




// 6.
// ! Brute/Worst:- T.C. => O(n^2), S.C. => O(1).
// signed main() {
// 	cin.tie(nullptr)->sync_with_stdio(false);
// 	int n;
// 	cin >> n;
	
// 	int prime = 0;
// 	for(int i = 1; i <= n; i++) {
// 		int count = 0;
// 		for(int j = 1; j <= i; j++) {
// 			if(i % j == 0) count++;
// 		}
// 		if(count == 2) {
// 			cout << i << " ";
// 			prime++;
// 		}
// 	}
// 	cout << endl << prime;
// }