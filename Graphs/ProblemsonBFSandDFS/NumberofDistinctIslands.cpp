//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, vector<pair<int,int>> &v, int row, int col, int pRow, int pCol){
        vis[row][col] = 1;
        v.push_back({row-pRow,col-pCol});
        int n = grid.size();
        int m =grid[0].size();
        int nRow[] = {-1,0,+1,0};
        int nCol[] = {0,-1,0,+1};
        for(int i=0 ; i<4 ; i++){
            int newRow = row+nRow[i];
            int newCol = col+nCol[i];
            if(newRow>=0 && newRow<n &&
            newCol>=0 && newCol<m &&
            grid[newRow][newCol] == 1 && vis[newRow][newCol] == 0
            ){
                dfs(grid,vis,v,newRow,newCol,pRow,pCol);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m =grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        set<vector<pair<int,int>>> s;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    vector<pair<int,int>> v;
                    dfs(grid,vis,v,i,j,i,j);
                    s.insert(v);
                }
            }
        }
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends
