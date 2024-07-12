//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int uniquePaths(int a, int b, vector<vector<int>> &grid) {
        int mod = (int) 1e9+7;
        vector <vector <int>> dp(a, vector <int>(b,0));
        for(int i=0 ; i<a ; i++){
            for(int j=0 ; j<b ; j++){
                if(grid[i][j] == 0){
                    dp[i][j] = 0;
                    continue;
                }
                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                    continue;
                } 
                int up = 0, left = 0;
                if(i>0) up = (dp[i-1][j])%mod;
                if(j>0) left = (dp[i][j-1])%mod;
                dp[i][j] = (up+left)%mod;
            }
        }
        return (dp[a-1][b-1])%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends
