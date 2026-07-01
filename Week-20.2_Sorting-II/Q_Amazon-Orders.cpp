#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

struct Order{
	int orderId;
	int timestamp;
	int priority;
};

bool customComparator(Order& order1, Order& order2) {
	if(order1.priority != order2.priority) {
		return order1.priority > order2.priority;
	}
	else if(order1.timestamp != order2.timestamp) {
		return order1.timestamp < order2.timestamp;
	}
	
	return order1.orderId < order2.orderId;
}

void amazonOrders(vector<Order>& vec) {
	sort(vec.begin(), vec.end(), customComparator);
	
	for(const auto& val : vec) {
		cout << val.orderId << " " << val.timestamp << " " << val.priority << endl;
	}
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int size;
	cin >> size;
	
	vector<Order> vec(size);
	
	for(int i = 0; i < size; i++) {
		cin >> vec[i].orderId >> vec[i].timestamp >> vec[i].priority;
	}
	
	amazonOrders(vec);
}