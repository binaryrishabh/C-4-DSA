#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

long long power(long long first, long long second, long long Modulo) {
    first %= Modulo;
    
    long long cal = 1;
    
    while (second > 0) {
        if (second & 1) {
            cal = cal * first % Modulo;
        }
        first = first * first % Modulo;
        second >>= 1;
    }
    return cal;


long long comb(long long num1, long long num2, vector<long long>& fact, vector<long long>& invFact, long long Modulo) {
    if (num2 < 0 || num1 < 0 || num2 > num1) {
        return 0;
    }
    return fact[num1] * invFact[num2] % Modulo * invFact[num1 - num2] % Modulo;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int size, k;
    cin >> size >> k;
    
    long long Modulo = 998244353;
    
    vector<int> vec(size, 0);
    
    for(int i = 0; i < size; i++) {
        cin >> vec[i];
    }
    
    vector<long long> fact(size + 1), invFact(size + 1);
    fact[0] = 1;
    for (int i = 1; i <= size; i++) {
        fact[i] = fact[i - 1] * i % Modulo;
    }
    
    invFact[size] = power(fact[size], Modulo - 2, Modulo);
    
    for (int i = size; i >= 1; i--) {
        invFact[i - 1] = invFact[i] * i % Modulo;
    }

    long long first = 0, second = 0;
    for (long long val : vec) {
        first = (first + val) % Modulo;
        second = (second + val * val) % Modulo;
    }

    long long third = comb(size - 1, k - 1, fact, invFact, Modulo);
    long long fourth = comb(size - 2, k - 2, fact, invFact, Modulo);

    long long ans = (third * second % Modulo + fourth * ((first * first % Modulo - second + Modulo) % Modulo) % Modulo) % Modulo;

    cout << ans;
}