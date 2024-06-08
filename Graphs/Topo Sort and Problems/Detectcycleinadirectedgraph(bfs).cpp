//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        int in_degree[V] = {0};
	    for(int i=0 ; i<V ; i++){
	        for(int x:adj[i]){
	            in_degree[x]++;
	        }
	    }
	    queue <int> q;
	    for(int i=0 ; i<V ; i++){
	        if(in_degree[i] == 0){
	            q.push(i);
	        }
	    }
	    int count = 0;
	    while(!q.empty()){
	        int u = q.front();
	        q.pop();
	        count++;
	        for(int v:adj[u]){
	            if(--in_degree[v] == 0){
	                q.push(v);
	            }
	        }
	    }
	    return (count != V);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
