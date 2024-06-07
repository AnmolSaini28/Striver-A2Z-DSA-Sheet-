//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    void bfs(vector<vector<char>>& grid, vector <vector<int>>& vis, int i, int j){
        int n = grid.size();
        int m = grid[0].size();
        queue <pair<int,int>> q;
        q.push({i,j});
        vis[i][j] = 1;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int nrow[] = {0,-1,0,+1,-1,-1,+1,+1};
            int ncol[] = {-1,0,+1,0,-1,+1,-1,+1};
            for(int i=0 ; i<8 ; i++){
                int newRow = row+nrow[i];
                int newCol = col+ncol[i];
                if(newRow>=0 && newRow<n &&
                newCol>=0 && newCol<m &&
                grid[newRow][newCol] == '1' &&
                vis[newRow][newCol] == 0
                ){
                    q.push({newRow,newCol});
                    vis[newRow][newCol] = 1;
                }
            }
        }
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector <vector<int>> vis(n ,vector<int>(m,0));
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                vis[i][j] = 0;
            }
        }
        int cnt = 0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == '1' && vis[i][j] == 0){
                    cnt++;
                    bfs(grid,vis,i,j);
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends
