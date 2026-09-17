#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int size, M;
    int K;
    cin >> size >> M >> K;
    vector<int> vec(size);
    for (auto &x : vec) cin >> x;

    deque<pair<int, int>> que;
    int sum = 0;

    for (int i = 0; i < size; i++) {
        while (!que.empty() && que.front().first < i - M + 1) {
            sum -= que.front().second;
            que.pop_front();
        }

        if (sum + vec[i] <= K) {
            cout << "Yes" << endl;
            sum += vec[i];
            que.push_back({i, vec[i]});
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}