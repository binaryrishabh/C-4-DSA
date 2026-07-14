#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

// Opitmal Approach
// T.C.-> O(N), S.C.-> O(N)
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void rightRectangle(vector<int>& right, vector<int>& vec) {
	stack<pair<int, int>> rightStack;
	
	for(int i = vec.size() - 1; i >= 0; i--) {
		int height = vec[i], width = 1;
		while(!rightStack.empty() && height <= rightStack.top().first) {
			width += rightStack.top().second;
			rightStack.pop();
		}
		
		right[i] = width;
		rightStack.push({height, width});
	}
}

void leftReactangle(vector<int>& left, vector<int>& vec) {
	stack<pair<int, int>> leftStack;
	
	for(int i = 0; i < vec.size(); i++) {
		int height = vec[i], width = 1;
		while(!leftStack.empty() && height <= leftStack.top().first) {
			width += leftStack.top().second;
			leftStack.pop();
		}
		
		left[i] = width;
		leftStack.push({height, width});
	}
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size;
	cin >> size;
	
	vector<int> vec(size, 0);
	
	for(int i = 0; i < size; i++) {
		cin >> vec[i];
	}
	
	vector<int> left(size, 0), right(size, 0);
	
	leftReactangle(left, vec);
	rightRectangle(right, vec);
	
	int area = INT_MIN;
	for(int i = 0; i < size; i++) {
		area = max(area, vec[i] * (right[i] + left[i] - 1));
	}
	cout << area;
}




// Brute Force Approach will give TLE for size = 10^5
// T.C.-> O(N^2), S.C.-> O(1)
/*
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size;
	cin >> size;
	
	vector<int> vec(size, 0);
	
	for(int i = 0; i < size; i++) {
		cin >> vec[i];
	}
	
	int maxArea = INT_MIN;
	
	for(int i = 0; i < size; i++) {
		int width = 1;
		int height = vec[i];
		
		// scan left for the current index.
		for(int j = i - 1; j >= 0; j--) {
			if(vec[j] >= height) {
				width++;
			}
			else break;
		}
		
		// scan right for the current index.
		for(int j = i + 1; j < size; j++) {
			if(vec[j] >= height) {
				width++;
			}
			else break;
		}
		
		maxArea = max(maxArea, height * width);
	}
	
	cout << maxArea;
}
*/