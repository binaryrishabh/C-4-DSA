#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void rightRectangle(vector<int>& right, vector<int>& base) {
	stack<pair<int, int>> rightStack;
	
	for(int i = base.size() - 1; i >= 0; i--) {
		int height = base[i], width = 1;
		while(!rightStack.empty() && height <= rightStack.top().first) {
			width += rightStack.top().second;
			rightStack.pop();
		}
		
		right[i] = width;
		
		rightStack.push({ height, width });
	}
}

void leftRectangle(vector<int>& left, vector<int>& base) {
	stack<pair<int, int>> leftStack;
	
	for(int i = 0; i < base.size(); i++) {
		int height = base[i], width = 1;
		while(!leftStack.empty() && height <= leftStack.top().first) {
			width += leftStack.top().second;
			leftStack.pop();
		}
		
		left[i] = width;
		
		leftStack.push({ height, width });
	}
}

int calculateArea(vector<int>& base) {
	vector<int> left(base.size(), 0), right(base.size(), 0);
	
	leftRectangle(left, base);
	rightRectangle(right, base);
	
	int area = INT_MIN;
	for(int i = 0; i < base.size(); i++) {
		area = max(area, base[i] * (left[i] + right[i] - 1));
	}
	
	return area;
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	
	vector<vector<char>> vec(n, vector<char>(m, 'x'));
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> vec[i][j];
		}
	}
	
	vector<int> base(m, 0);
	int area = INT_MIN;
	
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(vec[i][j] == '1') {
				base[j]++;
			}
			else {
				base[j] = 0;
			}
		}
		
		area = max(area, calculateArea(base));
	}
	
	
	// searching column wise
	/*
	vector<int> base(n, 0);
	int area = INT_MIN;
	
	for(int j = 0; j < m; j++) {
		for(int i = 0; i < n; i++) {
			if(vec[i][j] == '1') {
				base[i]++;
			}
			else {
				base[i] = 0;
			}
		}
		
		area = max(area, calculateArea(base));
	}
	*/
	cout << area;
}