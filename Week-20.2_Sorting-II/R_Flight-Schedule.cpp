#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

struct Flight {
	int flightNumber;
	int departureTime;
	string destination;
};

bool customComparator(Flight& flight1, Flight& flight2) {
	if(flight1.departureTime != flight2.departureTime) {
		return flight1.departureTime < flight2.departureTime;
	}
	
	return flight1.flightNumber < flight2.flightNumber;
}

void flightSchedule(vector<Flight>& vec) {
	sort(vec.begin(), vec.end(), customComparator);
	
	for(const auto& val : vec) {
		cout << val.flightNumber << " " << val.departureTime << " " << val.destination << endl;
	}
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size;
	cin >> size;
	
	vector<Flight> vec(size);
	
	for(int i = 0; i < size; i++) {
		cin >> vec[i].flightNumber >> vec[i].departureTime >> vec[i].destination;
	}
	
	flightSchedule(vec);
}