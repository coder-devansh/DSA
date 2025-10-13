class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid[0].size();
        int n=obstacleGrid.size();
        if(obstacleGrid[n-1][m-1]==1)return 0;
        vector<vector<long long>>dp(n+1,vector<long long>(m+1,0));
        dp[n-1][m-1]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(obstacleGrid[i][j])continue;
                dp[i][j]+=dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};