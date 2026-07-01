#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

// ! solved using 3-d vector

bool noAttack(int row, int col, int n, vector<vector<char>>& board) {
	
	// check same column
	int r = row, c = col;
	while(r >= 0) {
		if(board[r][c] == 'Q') {
			return false;
		}
		r--;
	}
	
	// check same left-up diagonal
	r = row, c = col;
	while(r >= 0 && c >= 0) {
		if(board[r][c] == 'Q') {
			return false;
		}
		r--; c--;
	}
	
	// check same right-up diagonal
	r = row, c = col;
	while(r >= 0 && c < n) {
		if(board[r][c] == 'Q') {
			return false;
		}
		r--; c++;
	}
	
	return true;
}

void queen(int row, int n, vector<vector<char>>& board, vector<vector<vector<char>>>& ans) {
	if(row == n) {
		ans.push_back(board);
		
		return;
	}
	
	for(int col = 0; col < n; col++) {
		if(noAttack(row, col, n, board)) {
			board[row][col] = 'Q';
			queen(row + 1, n, board, ans);
			board[row][col] = '.';
		}
	}
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	vector<vector<char>> board(n, vector<char>(n, '.'));
	
	vector<vector<vector<char>>> ans;
	
	queen(0, n, board, ans);
	
	cout << ans.size() << endl;
	
	for(const auto& twoDVec : ans) {
		for(const auto& oneDVec: twoDVec) {
			for(const auto& val : oneDVec) {
				cout << val;
			}
			cout << endl;
		}
		cout << endl;
	}
}