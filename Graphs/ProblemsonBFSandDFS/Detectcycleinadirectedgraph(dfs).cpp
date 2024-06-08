//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    bool dfs(vector<int> adj[], vector<int> &vis, vector<int> &recSt, int s){
        vis[s] = 1;
        recSt[s] = 1;
        for(int u:adj[s]){
            if(vis[u] == 0){
                if(dfs(adj,vis,recSt,u) == true){
                    return true;
                }
            }
            else if(recSt[u] == 1){
                return true;
            }
        }
        recSt[s] = 0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>vis (V,0);
        vector<int>recSt (V,0); 
        
        for(int i=0 ; i<V ; i++){
            if(vis[i] == 0){
                if(dfs(adj,vis,recSt,i) == true){
                    return true;
                }
            }
        }
        
        return false;
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
