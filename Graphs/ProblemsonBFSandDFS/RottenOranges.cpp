//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue <pair<pair<int,int>, int>> q;
        int cntFresh = 0;
        
        int vis[n][m];
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == 1){
                    cntFresh++;
                    vis[i][j] = 0;
                }
                else if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }
        
        int time = 0;
        int cnt = 0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time,t);
            int nRow[] = {-1,0,+1,0};
            int nCol[] = {0,-1,0,+1};
            for(int i=0 ; i<4 ; i++){
                int newRow = row+nRow[i];
                int newCol = col+nCol[i];
                if(newRow >=0 && newRow < n && newCol >=0 && newCol < m && grid[newRow][newCol] == 1 && vis[newRow][newCol] == 0){
                    q.push({{newRow, newCol}, t+1});
                    vis[newRow][newCol] = 2;
                    cnt++;
                }
            }
        }
        
        if(cntFresh != cnt) return -1;
        
        return time;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
