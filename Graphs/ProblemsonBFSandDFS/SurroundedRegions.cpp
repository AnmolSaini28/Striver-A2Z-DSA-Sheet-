//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    void dfs(int n, int m, vector<vector<char>> &mat, vector<vector<int>> &vis, int row, int col){
        vis[row][col] = 1;
        
        int delrow[] = {-1, 0 , 1 ,0};
        int delcol[] = {0 ,1, 0 ,-1};
        //check on four directions
        for(int i=0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >=0 && nrow <n && ncol>=0 && ncol <m &&
            vis[nrow][ncol] == 0 && mat[nrow][ncol] == 'O'
            ){
                dfs(n,m,mat, vis, nrow, ncol);
            }
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<char>> ans = mat;
        vector<vector<int>> vis(n ,vector<int>(m,0));
        for(int i=0 ; i<m ; i++){
            if(mat[0][i] == 'O' && vis[0][i] == 0){
                dfs(n,m,mat,vis,0,i);
            }
            if(mat[n-1][i] == 'O' && vis[n-1][i] == 0){
                dfs(n,m,mat,vis,n-1,i);
            }
        }
        for(int i=0 ; i<n ; i++){
            if(mat[i][0] == 'O' && vis[i][0] == 0){
                dfs(n,m,mat,vis,i,0);
            }
            if(mat[i][m-1] == 'O' && vis[i][m-1] == 0){
                dfs(n,m,mat,vis,i,m-1);
            }
        }
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(mat[i][j] == 'O' && vis[i][j] == 0){
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
