class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<long long>>dp(n+1,vector<long long>(m+1,0));
        for(int i=0;i<grid.size();i++){
            dp[i][m]=INT_MAX;
        }
        for(int j=0;j<grid[0].size();j++){
            dp[n][j]=INT_MAX;
        }
        dp[n-1][m-1]=grid[n-1][m-1];
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1)continue;
                dp[i][j]=grid[i][j]+min(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0];


        
    }
};