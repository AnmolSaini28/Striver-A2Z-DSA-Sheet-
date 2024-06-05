//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        vector <vector<int>> ans = image;
        queue<pair<int,int>> q;
        int vis[n][m];
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                vis[i][j] = false;
            }
        }
        q.push({sr,sc});
        ans[sr][sc] = newColor;
        vis[sr][sc] = true;
        int nRow[] = {-1,0,+1,0};
        int nCol[] = {0,-1,0,+1};
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            ans[row][col] = newColor;
            for(int i=0 ; i<4 ; i++){
                for(int j=0 ; j<4 ; j++){
                    int newRow = row+nRow[i];
                    int newCol = col+nCol[i];
                    if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && image[newRow][newCol] == image[row][col] && vis[newRow][newCol] == false){
                        q.push({newRow,newCol});
                        vis[newRow][newCol] = true;
                    }
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
