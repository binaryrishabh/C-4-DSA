#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size1, size2;
	cin >> size1 >> size2;
	
	vector<int> vec1(size1, 0);
	
	for(int p = 0; p < size1; p++) {
		cin >> vec1[p];
	}
	
	vector<int> vec2(size2, 0);
	
	for(int p = 0; p < size2; p++) {
		cin >> vec2[p];
	}
	
	vector<int> vec3(size1 + size2, 0);
	
	int i = 0, j = 0, k = 0;
	
	while(i < size1 && j < size2) {
		if(vec1[i] < vec2[j]) {
			vec3[k++] = vec1[i++];
		}
		else {
			vec3[k++] = vec2[j++];
		}
	}
	
	while(i < size1) {
		vec3[k++] = vec1[i++];
	}
	
	while(j < size2) {
		vec3[k++] = vec2[j++];
	}
	
	for(int p = 0; p < vec3.size(); p++) {
		cout << vec3[p] << " ";
	}
}