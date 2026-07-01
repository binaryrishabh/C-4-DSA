#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void rat(string path, int row, int col, int n, vector<vector<bool>>& visited, vector<vector<int>>& maze, set<string>& pathSet) {
	if(row < 0 || col < 0 || row >= n || col >= n || maze[row][col] == 0) return;
	
	if(row == n - 1 && col == n - 1) {
		pathSet.insert(path);
		return;
	}
	
	// Down
	if(row < n - 1 && !visited[row + 1][col] && maze[row + 1][col] == 1) {
		visited[row + 1][col] = true;
		path.push_back('D');
		rat(path, row + 1, col, n, visited, maze, pathSet);
		path.pop_back();
		visited[row + 1][col] = false;
	}
	
	// Left
	if(col > 0 && !visited[row][col - 1] && maze[row][col - 1] == 1) {
		visited[row][col - 1] = true;
		path.push_back('L');
		rat(path, row, col - 1, n, visited, maze, pathSet);
		path.pop_back();
		visited[row][col - 1] = false;
	}
	
	// Right
	if(col < n - 1 && !visited[row][col + 1] && maze[row][col + 1] == 1) {
		visited[row][col + 1] = true;
		path.push_back('R');
		rat(path, row, col + 1, n, visited, maze, pathSet);
		path.pop_back();
		visited[row][col + 1] = false;
	}
	
	// UP
	if(row > 0 && !visited[row - 1][col] && maze[row - 1][col] == 1) { 
		visited[row - 1][col] = true;
		path.push_back('U');
		rat(path, row - 1, col, n, visited, maze, pathSet);
		path.pop_back();
		visited[row - 1][col] = false;
	}
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	vector<vector<int>> maze(n, vector<int>(n));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			int val;
			cin >> val;
			
			maze[i][j] = val;
		}
	}
	
	vector<vector<bool>> visited(n, vector<bool>(n, 0));
	visited[0][0] = true;
	
	set<string> pathSet;
	
	rat("", 0, 0, n, visited, maze, pathSet);
	
	if(pathSet.size() == 0) cout << 0;
	else {
		cout << pathSet.size() << endl;
		for(const auto& val : pathSet) cout << val << endl;
	}
}