#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int test;
	cin >> test;
	while(test--) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<int>> adj(n + 1);
        
        vector<int> vec1(m), vec2(m);
        
        for(int i = 0; i < m; i++){
            int first, second;
            cin >> first >> second;
            
            vec1[i] = first;
            vec2[i] = second;
            
            adj[first].push_back(second);
            adj[second].push_back(first);
        }
        
        vector<int> color(n + 1, -1), depth(n + 1, -1), parent(n + 1, 0);
        
        queue<int> que;
        
        color[1] = 0;
        depth[1] = 0;
        
        que.push(1);
        
        while(!que.empty()){
            int first = que.front();
            que.pop();
            for(int second : adj[first]){
                if(color[second] == -1){
                    color[second] = color[first] ^ 1;
                    depth[second] = depth[first] + 1;
                    parent[second] = first;
                    que.push(second);
                }
            }
        }
        
        int badEdge = -1;
        for(int i = 0;i < m; i++){
            if(color[vec1[i]] == color[vec2[i]]) {
            	badEdge = i;
            	break;
            }
        }
        
        if(badEdge == -1){
            cout << -1 << endl;
        } 
        else {
            int first = vec1[badEdge], second = vec2[badEdge];
            vector<int> pfirst, psecond;
            int x=first, y=second;
            while(depth[x]>depth[y]) {
            	pfirst.push_back(x);
            	x=parent[x];
            }
            while(depth[y]>depth[x]) { 
            	psecond.push_back(y); 
            	y=parent[y]; 
            }
            while(x!=y) { 
            	pfirst.push_back(x); 
            	psecond.push_back(y); 
            	x=parent[x]; 
            	y=parent[y]; 
            }
            
            pfirst.push_back(x);

            vector<int> cycle = pfirst;
            
            for(int index = psecond.size() - 1; index >= 0; index--) {
            	cycle.push_back(psecond[index]);
            }

            cout << cycle.size() << endl;
            
            for(int index = 0; index < cycle.size(); index++) {
                cout << cycle[index];
                if(index + 1 < cycle.size()) {
                    cout << " ";
                } 
                else {
                    cout << endl;
                }
            }
        }
    }
}