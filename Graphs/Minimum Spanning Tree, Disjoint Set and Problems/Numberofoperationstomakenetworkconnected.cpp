//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DisjointSet{
      public:
      vector<int> parent, size;
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
class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        DisjointSet ds(n);
        int cntExtra = 0;
        for(auto it : edge){
            int u = it[0];
            int v = it[1];
            if(ds.findparent(u) == ds.findparent(v)){
                cntExtra++;
            }
            else{
                ds.Union(u,v);
            }
        }
        int cntCon = 0;
        for(int i=0 ; i<n ; i++){
            if(ds.parent[i] == i){
                cntCon++;
            }
        }
        int ans = cntCon-1;
        if(cntExtra >= ans){
            return ans;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends
