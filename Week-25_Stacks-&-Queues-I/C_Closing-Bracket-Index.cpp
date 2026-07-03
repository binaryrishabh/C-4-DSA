#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

// Tracking the index
signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s;
    cin >> s;
    int p;
    cin >> p;

    // If the given index doesn't have '(', no matching bracket exists
    if (s[p] != '(') {
        cout << -1;
        return 0;
    }

    stack<int> st; // store indices instead of chars

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } 
        else if (s[i] == ')') {
            int openIdx = st.top();
            st.pop();
            if (openIdx == p) {
                cout << i;
                return 0;
            }
        }
    }

    cout << -1;
}


// Tracking the brackets
// signed main() {
// 	cin.tie(nullptr)->sync_with_stdio(false);
// 	string s;
// 	cin >> s;
	
// 	int p;
// 	cin >> p;
	
	
// 	stack<char> st;
	
// 	for(int i = 0; i < s.size(); i++) {
// 		char ch = s[i];
		
// 		if(ch == '(') {
// 			if(i == p) {
// 				st.push('x');
// 			}
// 			else {
// 				st.push('(');
// 			}
// 		}
// 		else if(ch == ')') {
// 			char t = st.top();
// 			if(t == 'x') {
// 				cout << i;
// 				return 0;
// 			}
// 			else {
// 				st.pop();
// 			}
// 		}
// 	}
	
// 	cout << -1;
// }