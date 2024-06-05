//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    bool bfs(vector<int> adj[], bool vis[], int s, int parent[]){
        vis[s] = true;
        parent[s] = -1;
        queue<int> q;
        q.push(s);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v:adj[u]){
                if(!vis[v]){
                    q.push(v);
                    vis[v] = true;
                    parent[v] = u;
                }
                else if(vis[v] && parent[u] != v){
                    return true;
                }
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        bool vis[V];
        int parent[V];
        for(int i=0 ; i<V ; i++){
            vis[i] = false;
            parent[i] = 0;
        }
        for(int i=0 ; i<V ; i++){
            if(vis[i] == false){
                if(bfs(adj,vis,i,parent) == true){
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
