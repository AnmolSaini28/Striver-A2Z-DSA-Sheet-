//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

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
    int maxRemove(vector<vector<int>>& stones, int n) {
        int maxRow = 0;
        int maxCol = 0;
        for (auto it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int, int> stoneNodes;
        for (auto it : stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            ds.Union(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }

        int cnt = 0;
        for (auto it : stoneNodes) {
            if (ds.findparent(it.first) == it.first) {
                cnt++;
            }
        }
        return n - cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends
