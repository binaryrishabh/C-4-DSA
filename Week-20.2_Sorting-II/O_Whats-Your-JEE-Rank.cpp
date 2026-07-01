#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

struct Student {
	string name;
	int totalMarks;
	int physMarks;
	int chemMarks;
	int mathMarks;
};

bool customComparator(Student stud1, Student stud2) {
	if(stud1.totalMarks != stud2.totalMarks) {
		return stud1.totalMarks > stud2.totalMarks;
	}
	else if(stud1.mathMarks != stud2.mathMarks) {
		return stud1.mathMarks > stud2.mathMarks;
	}
	else if(stud1.physMarks != stud2.physMarks) {
		return stud1.physMarks > stud2.physMarks;
	}
	
	return stud1.name < stud2.name;
}

void jeeMark(vector<Student> vec) {
	sort(vec.begin(), vec.end(), customComparator);
	
	for(const auto& val : vec) {
		cout << val.name << " " << val.totalMarks << " " << val.physMarks << " " << val.chemMarks << " " << val.mathMarks << endl;
	}
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size;
	cin >> size;
	
	vector<Student> vec(size);
	
	for(int i = 0; i < size; i++) {
		cin >> vec[i].name >> vec[i].totalMarks >> vec[i].physMarks >> vec[i].chemMarks >> vec[i].mathMarks;
	}
	
	jeeMark(vec);
}