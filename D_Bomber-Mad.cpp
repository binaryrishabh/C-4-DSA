#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int size, W, K;
    cin >> size >> W >> K;

    vector<string> vec(size);
    for (int i = 0; i < size; i++) {
    	cin >> vec[i];
    }

    vector<char> rowHasBomb(size, 0), colHasBomb(W, 0);
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < W; j++) {
            if (vec[i][j] == '#') {
                rowHasBomb[i] = 1;
                colHasBomb[j] = 1;
            }
        }
    }

    vector<int> dist(size * W, -1);
    queue<int> que;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < W; j++) {
            if (vec[i][j] == '.' && !rowHasBomb[i] && !colHasBomb[j]) {
                int index = i * W + j;
                dist[index] = 0;
                que.push(index);
            }
        }
    }

    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, -1, 1};

    while (!que.empty()) {
        int current = que.front(); 
        que.pop();
        int coli = current / W, colj = current % W;
        for (int k = 0; k < 4; k++) {
            int ni = coli + di[k], nj = colj + dj[k];
            if (ni < 0 || ni >= size || nj < 0 || nj >= W) {
            	continue;
            }
            if (vec[ni][nj] == '#') {
            	continue;
            }
            int nindex = ni * W + nj;
            if (dist[nindex] == -1) {
                dist[nindex] = dist[current] + 1;
                que.push(nindex);
            }
        }
    }

    int count = 0;
    for (int index = 0; index < size * W; index++) {
        if (dist[index] != -1 && dist[index] <= K) {
        	count++;
        }
    }

    cout << count << endl;
}