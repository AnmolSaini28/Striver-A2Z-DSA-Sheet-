class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue <pair<pair<int,int> ,int>> q;
        vector<vector<int>> ans(n, vector<int>(m,0));
        vector<vector<int>> vis(n, vector<int>(m,0));
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();
            ans[row][col] = t;
            int nRow[] = {-1,0,+1,0};
            int nCol[] = {0,-1,0,+1};
            for(int i=0 ; i<4 ; i++){
                int newRow = row+nRow[i];
                int newCol = col+nCol[i];
                if(newRow>=0 && newRow<n && 
                newCol>=0 && newCol<m && 
                mat[newRow][newCol] == 1 && vis[newRow][newCol] == 0){
                    q.push({{newRow,newCol},t+1});
                    vis[newRow][newCol] = 1;
                }
            }
        }
        return ans;
        
    }
};
