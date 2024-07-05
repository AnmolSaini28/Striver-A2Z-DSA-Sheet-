//{ Driver Code Starts
// Initial Template for C++
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
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        int n = accounts.size();
        int m = accounts[0].size();
        DisjointSet ds(n);
        sort(accounts.begin(), accounts.end());
        unordered_map <string,int> mapMailNode;
        for(int i=0 ; i<n ; i++){
            for(int j=1 ; j<accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mapMailNode.find(mail) == mapMailNode.end()){
                    mapMailNode[mail] = i;
                }
                else{
                    ds.Union(i,mapMailNode[mail]);
                }
            }
        }
        vector <string> mergeMail[n];
        for(auto it : mapMailNode){
            string mail = it.first;
            int node = ds.findparent(it.second);
            mergeMail[node].push_back(mail);
        }
        vector <vector<string>> ans;
        for(int i=0 ; i<n ; i++){
            if(mergeMail[i].size() == 0) continue;
            sort(mergeMail[i].begin(),mergeMail[i].end());
            string name = accounts[i][0];
            vector <string> temp;
            temp.push_back(name);
            for(auto it : mergeMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<string>> accounts;

        for (int i = 0; i < n; i++) {
            vector<string> temp;
            int x;
            cin >> x;

            for (int j = 0; j < x; j++) {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            accounts.push_back(temp);
        }

        ///
        Solution obj;
        vector<vector<string>> res = obj.accountsMerge(accounts);
        sort(res.begin(), res.end());
        cout << "[";
        for (int i = 0; i < res.size(); ++i) {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++) {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], " << endl;
            else
                cout << "]";
        }
        cout << "]" << endl;
    }
}
// } Driver Code Ends
