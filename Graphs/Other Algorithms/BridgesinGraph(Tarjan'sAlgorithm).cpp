class Solution {
    private:
    int timer = 1;
    void dfs(vector <int> adj[], vector <int> &vis, int node, int parent, int tin[], int low[], vector <vector <int>> &bridges){
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for(auto it : adj[node]){
            if(it == parent) continue;
            if(!vis[it]){
                dfs(adj,vis,it,node,tin,low,bridges);
                low[node] = min(low[node], low[it]);
                if(low[it] > tin[node]){
                    bridges.push_back({it,node});
                }
            }
            else{
                low[node] = min(low[node], low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector <int> adj[n];
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector <int> vis(n,0);
        int tin[n];
        int low[n];
        vector <vector <int>> bridges;
        dfs(adj,vis,0,-1,tin,low,bridges);
        return bridges;
    }
};
