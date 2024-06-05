//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    bool dfs(vector<int> adj[], int s, vector<bool> &vis, int parent){
        vis[s] = true;
        for(auto v:adj[s]){
            if(vis[v] && v != parent)
              return 1;
              
            else if(!vis[v] && dfs(adj, v, vis, s)){
                return 1;
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V, false);
        for(int i=0 ; i<V ; i++){
            vis[i] = false;
        }
        for(int i=0 ; i<V ; i++){
            if(vis[i] == false){
                if(dfs(adj,i,vis,-1) == true){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
