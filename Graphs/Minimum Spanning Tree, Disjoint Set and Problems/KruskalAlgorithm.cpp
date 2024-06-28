//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	class DisjointSet{
      
      vector<int> parent, size;
      
      public:
      
      DisjointSet(int n){
          
          parent.resize(n+1);
          for(int i=0; i<n+1; i++)
             parent[i] = i;
          size.resize(n+1, 1);
          
      }
      
      int findparent(int node){
          
          if(node == parent[node])
             return node;
             
          // Path compression
          return parent[node] = findparent(parent[node]);
          
      }
      
      void Union(int u, int v){
          
          int ulp_u = findparent(u);
          int ulp_v = findparent(v);
          
          if(ulp_u == ulp_v)
             return;
             
          else if(size[ulp_u] > size[ulp_v]){
              parent[ulp_v] = ulp_u;
              size[ulp_v] += size[ulp_u];
          }else{
              parent[ulp_u] = ulp_v;
              size[ulp_u] += size[ulp_v];
          }
          
      }
        
    };
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector <pair <int, pair<int , int>>> edges;
        for(int i=0 ; i<V ; i++){
            for(auto it : adj[i]){
                int wt = it[1];
                int u = i;
                int v = it[0];
                edges.push_back({wt,{u,v}});
            }
        }
        sort(edges.begin(), edges.end());
        int sum = 0;
        DisjointSet ds(V);
        for(auto it : edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if(ds.findparent(u) != ds.findparent(v)){
                sum += wt;
                ds.Union(u,v);
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
