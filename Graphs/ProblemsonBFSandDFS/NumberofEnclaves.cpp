//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        int vis[n][m];
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                vis[i][j] = 0;
            }
        }
        queue<pair<int,int>> q;
        for(int i=0 ; i<m ; i++){
            if(grid[0][i] == 1){
                q.push({0,i});
                vis[0][i] = 1;
            }
            if(grid[n-1][i] == 1){
                q.push({n-1,i});
                vis[n-1][i] = 1;
            }
        }
        for(int i=0 ; i<n ; i++){
            if(grid[i][0] == 1){
                q.push({i,0});
                vis[i][0] = 1;
            }
            if(grid[i][m-1] == 1){
                q.push({i,m-1});
                vis[i][m-1] = 1;
            }
        }
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int nrow[] = {0,-1,0,+1};
            int ncol[] = {-1,0,+1,0};
            for(int i=0 ; i<4 ; i++){
                int newRow = row+nrow[i];
                int newCol = col+ncol[i];
                if(newRow>=0 && newRow<n && 
                newCol>=0 && newCol<m && 
                grid[newRow][newCol] == 1 && 
                vis[newRow][newCol] == 0){
                    q.push({newRow,newCol});
                    vis[newRow][newCol] = 1;
                }
            }
        }
        int cnt = 0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    cnt++;
                }
            }
        }
        return cnt;
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
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends
