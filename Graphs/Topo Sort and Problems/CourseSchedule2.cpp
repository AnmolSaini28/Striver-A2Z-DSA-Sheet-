//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int V, int m, vector<vector<int>> prerequisites) 
    {
        vector <int> adj[V];
	    for(auto it : prerequisites){
	        adj[it[1]].push_back(it[0]);
	    }
	    int in_degree[V] = {0};
	    for(int i=0 ; i<V ; i++){
	        for(int x:adj[i]){
	            in_degree[x]++;
	        }
	    }
	    queue <int> q;
	    vector <int> ans;
	    for(int i=0 ; i<V ; i++){
	        if(in_degree[i] == 0){
	            q.push(i);
	        }
	    }
	    while(!q.empty()){
	        int u = q.front();
	        q.pop();
	        ans.push_back(u);
	        for(int v:adj[u]){
	            if(--in_degree[v] == 0){
	                q.push(v);
	            }
	        }
	    }
	    if(ans.size() == V)
	    return ans;
	    
	    return {};
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends
