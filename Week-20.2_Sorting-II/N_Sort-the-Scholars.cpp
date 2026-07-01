#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

struct Student {
	string name;
	int marks;
};

bool customComparator(Student stud1, Student stud2) {
	if(stud1.marks != stud2.marks) {
		return stud1.marks > stud2.marks;
	}
	
	return stud1.name < stud2.name;
}

void sortScholar(vector<Student>& vec) {
	sort(vec.begin(), vec.end(), customComparator);
	
	for(const auto& val : vec) {
		cout << val.name << " " << val.marks << endl;
	}
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size;
	cin >> size;
	
	vector<Student> vec(size);
	
	for(int i = 0; i < size; i++) {
		cin >> vec[i].name >> vec[i].marks;
	}
	
	sortScholar(vec);
}