#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void merge(int left, int mid, int right, vector<int>& vec) {
	int i = left, j = mid + 1, k = 0;
	
	vector<int> temp(right - left + 1, 0);
	
	while(i <= mid && j <= right) {
		if(vec[i] <= vec[j]) {
			temp[k++] = vec[i++];
		}
		else {
			temp[k++] = vec[j++];
		}
	}
	
	while(i <= mid) {
		temp[k++] = vec[i++];
	}
	
	while(j <= right) {
		temp[k++] = vec[j++];
	}
	
	int ptr = 0;
	for(int i = 0; i < temp.size(); i++) {
		vec[left + i] = temp[i];
	}
}

void mergeSort(int left, int right, vector<int>& vec) {
	if(left >= right) {
		return;
	}
	
	int mid = left + (right - left) / 2;
	
	mergeSort(left, mid, vec);
	mergeSort(mid + 1, right, vec);
	
	merge(left, mid, right, vec);
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size;
	cin >> size;
	
	vector<int> vec(size, 0);
	
	for(int i = 0; i < size; i++) {
		cin >> vec[i];
	}
	
	mergeSort(0, size - 1, vec);
	
	for(int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
}