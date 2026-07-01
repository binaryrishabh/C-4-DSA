#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size;
	cin >> size;
	
	int arr[size];
	
	for(int i = 0; i < size; i++) {
		int val;
		cin >> val;
		
		arr[i] = val;
	}

}



// . TLE
// ! Using Sieve divisor Method with Optimized Sieve of Eratosthenes using MAPS
// ! Better:- T.C. => O(size + max_val*log(max_val) + max_prime_possible +
// ! max_prime_possible*log(log(max_prime_possible)) + size), S.C. => O(max_val + max_prime_possible).
// signed main() {
// 	cin.tie(nullptr)->sync_with_stdio(false);
// 	int size;
// 	cin >> size;
	
// 	unordered_map<int, int> maps;
	
// 	int max_val = INT_MIN;
	
// 	int query[size];
	
// 	for(int i = 0; i < size; i++) {
// 		int val;
// 		cin >> val;
		
// 		query[i] = val;
		
// 		maps.insert({val, 0});
// 		max_val = max(max_val, val);
// 	}
	
// 	int max_prime_possible = INT_MIN;
	
// 	// Sieve Divisor approach
// 	for(int i = 1; i <= max_val; i++) {
// 		for(int j = i; j <= max_val; j += i) {
// 			if(maps.find(j) != maps.end()) {
// 				maps[j]++;
// 				max_prime_possible = max(max_prime_possible, maps[j]);
// 			}
// 		}
// 	}
	
// 	bool isPrime[max_prime_possible + 1];
// 	isPrime[0] = false;
// 	isPrime[1] = false;
// 	for(int i = 2; i <= max_prime_possible; i++) {
// 		isPrime[i] = true;
// 	}
	
	
// 	// Optimized Sieve of Eratosthenes
// 	for(int i = 2; i * i <= max_prime_possible; i++) {
// 		if(isPrime[i]) {
// 			for(int j = i * i; j <= max_prime_possible; j += i) {
// 				isPrime[j] = false;
// 			}
// 		}
// 	}
	
// 	for(int val : query) {
// 		if(isPrime[maps[val]]) cout << "YES";
// 		else cout << "NO";
		
// 		cout << endl;
// 	}
// }