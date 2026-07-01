#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

struct Points {
	int x;
	int y;
	int distance;
};

bool customComparator(Points firstPoint, Points secondPoint) {
	if(firstPoint.distance != secondPoint.distance) {
		return firstPoint.distance < secondPoint.distance;
	}
	else if(firstPoint.x != secondPoint.x) {
		return firstPoint.x < secondPoint.x;
	}
	
	return firstPoint.y < secondPoint.y;
}

void closestPoint(vector<Points>& vec) {
	sort(vec.begin(), vec.end(), customComparator);
	
	for(const auto& val : vec) {
		cout << val.x << " " << val.y << endl;
	}
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size, a, b;
	cin >> size >> a >> b;
	
	vector<Points> vec(size);
	
	for(int i = 0; i < size; i++) {
		int x, y;
		cin >> x >> y;
		
		vec[i].x = x;
		vec[i].y = y;
		
		int xa = x - a, yb = y - b;
		
		
		vec[i].distance = (xa * xa) + (yb * yb);
	}
	
	closestPoint(vec);
}