//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        int n = grid.size();
        int m = grid[0].size();
        queue <pair<pair<int,int> ,int>> q;
        vector<vector<int>> vis(n, vector<int>(m,0));
        int ans = INT_MAX;
        int r1 = source.first;
        int c1 = source.second;
        int r2 = destination.first;
        int c2 = destination.second;
        q.push({{r1,c1},0});
        vis[r1][c1] = 1;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            if(row == r2 && col == c2){
                ans = min(ans,dis);
            }
            int nRow[] = {-1,0,+1,0};
            int nCol[] = {0,-1,0,+1};
            for(int i=0 ; i<4 ; i++){
                int newRow = row+nRow[i];
                int newCol = col+nCol[i];
                if(newRow>=0 && newRow<n && 
                newCol>=0 && newCol<m && 
                grid[newRow][newCol] == 1 && vis[newRow][newCol] == 0){
                    q.push({{newRow,newCol},dis+1});
                    vis[newRow][newCol] = 1;
                }
            }
        }
        return (ans == INT_MAX)? -1 : ans;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends
