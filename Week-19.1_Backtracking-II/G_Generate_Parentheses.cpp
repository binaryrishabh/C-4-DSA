#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void generate(int opening, int closing, int n, vector<string> innerVec, vector<vector<string>>& outerVec) {
	if(opening == n && closing == n) {
		outerVec.push_back(innerVec);
		return;
	}
	
	if(opening < n) {
		innerVec.push_back("(");
		generate(opening + 1, closing, n, innerVec, outerVec);
		innerVec.pop_back();
	}
	
	if(opening > closing) {
		innerVec.push_back(")");
		generate(opening, closing + 1, n, innerVec, outerVec);
		innerVec.pop_back();
	}
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	vector<string> innerVec;
	vector<vector<string>> outerVec;
	
	generate(0, 0, n, innerVec, outerVec);
	
	cout << outerVec.size() << endl;
	
	for(vector<string> vec : outerVec) {
		for(const auto& val : vec) {
			cout << val;
		}
		cout << endl;
	}
}