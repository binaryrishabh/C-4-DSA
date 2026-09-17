#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int size;
    cin >> size;
    vector<int> vec(size);
    int total = 0;
    for (int i = 0; i < size; i++) {
        cin >> vec[i];
        total += vec[i];
    }

    int best = -1;
    int left = 0;
    for (int i = 0; i < size - 1; i++) {
        left += vec[i];
        int right = total - left;
        int diff = abs(left - right);
        if (best == -1 || diff < best) {
            best = diff;
        }
    }

    cout << best;
}