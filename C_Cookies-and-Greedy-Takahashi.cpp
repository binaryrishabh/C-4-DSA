#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size;
	cin >> size;
	
	vector<int> vecPos;
	vector<int> vecNeg;
	
	for(int i = 0; i < size; i++) {
		int val;
		cin >> val;
		
		if(val >= 0) {
			vecPos.push_back(val);
		}
		else {
			vecNeg.push_back(val);
		}
	}
	
	sort(vecPos.begin(), vecPos.end());
	sort(vecNeg.begin(), vecNeg.end());

	reverse(vecNeg.begin(), vecNeg.end());

	int pos = 0, neg = 0, position = 0, distance = 0;
	while(pos < vecPos.size() && neg < vecNeg.size()) {
		int leftMove = position - vecNeg[neg];
		int rightMove = vecPos[pos] - position;
		
		if(leftMove <= rightMove) {
			position -= leftMove;
			neg++;
			distance += leftMove;
		}
		else {
			position += rightMove;
			pos++;
			distance += rightMove;
		}
	}

	while(pos < vecPos.size()) {
		int rightMove = vecPos[pos] - position;
	
		position += rightMove;
		pos++;
		distance += rightMove;		
	}

	while(neg < vecNeg.size()) {
		int leftMove = position - vecNeg[neg];
		
		position -= leftMove;
		neg++;
		distance += leftMove;		
	}

	cout << distance;
}