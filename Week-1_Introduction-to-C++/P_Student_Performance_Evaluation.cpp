#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int marks;
	cin >> marks;
	
	if(marks > 90) cout << "Excellent";
	else if(marks > 80 && marks <= 90) cout << "Good";
	else if(marks > 70 && marks <= 80) cout << "Fair";
	else if(marks > 60 && marks <= 70) cout << "Meets Expectations";
	else cout << "Below Par";
}