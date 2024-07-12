class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int a = grid.size();
        int b = grid[0].size();
        vector <vector <int>> dp(a, vector <int>(b,0));
        for(int i=0 ; i<a ; i++){
            for(int j=0 ; j<b ; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = grid[i][j];
                    continue;
                } 
                int up = grid[i][j], left = grid[i][j];
                if(i>0) up += dp[i-1][j];
                else up += 1e9;
                if(j>0) left += dp[i][j-1];
                else left += 1e9;
                dp[i][j] = min(up, left);
            }
        }
        return dp[a-1][b-1];
    }
};
