#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

bool canPlace(char ch, int row, int col, vector<vector<char>>& board) {
	
	// check in same row.
	for(int c = 0; c < 9; c++) {
		if(board[row][c] == ch) {
			return false;
		}
	}
	
	// check in same col
	for(int r = 0; r < 9; r++) {
		if(board[r][col] == ch) {
			return false;
		}
	}
	
	// checking inside there 3*3 small grids;
	int sr = (row / 3) * 3, sc = (col / 3) * 3;
	for(int i = sr; i < sr + 3; i++) {
		for(int j = sc; j < sc + 3; j++) {
			if(board[i][j] == ch) {
				return false;
			}
		}
	}
	
	return true;
}

bool suduko(int row, int col, vector<vector<char>>& board) {
	
	// got the solution 
	if(row >= 9) {
		// print the solution
		for(vector<char> vec : board) {
			for(const auto& val : vec) {
				cout << val;
			}
			cout << endl;
		}
		
		return true;
	}
	
	// reached the last column
	if(col >= 9) {
		return suduko(row + 1, 0, board); // go to next row
	}
	
	bool solved = false; // for marking that we found the solution or not??
	
	// skip as value already given by the creator.
	if(board[row][col] != '.') {
		solved = suduko(row, col + 1, board);
	}
	// Try placing a digit between 1-9.
	else {
		for(int val = 1; val <= 9; val++) {
			char ch = (char)(val + 48);
			if(canPlace(ch, row, col, board)) {
				board[row][col] = ch;
				solved = suduko(row, col + 1, board);
				if(solved) return true;
				board[row][col] = '.';
			}
		}
	}
	
	return solved;
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	vector<vector<char>> board(9, vector<char>(9, '.'));
	
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++) {
			char ch;
			cin >> ch;
			
			board[i][j] = ch;
		}
	}
	
	suduko(0, 0, board);
}