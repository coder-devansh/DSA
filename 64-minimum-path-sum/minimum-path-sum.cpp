class Solution {
public:
// recursive way

int find(int i,int j,int n,int m,vector<vector<int>>&grid,vector<vector<int>>&dp){
    if(i==n-1 && j==m-1){
        return grid[i][j];
    }
    if(i<0 || j<0 || i>=n || j>=m){
        return INT_MAX;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int left=find(i+1,j,n,m,grid,dp);
    int right=find(i,j+1,n,m,grid,dp);
    return dp[i][j]=min(left,right)+grid[i][j];
}
    int minPathSum(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,1e9));
        dp[n-1][m-1]=grid[n-1][m-1];
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                 if (i == n - 1 && j == m - 1) continue; // already filled
                dp[i][j]=min(dp[i+1][j],dp[i][j+1])+grid[i][j];
            }
        }
        return dp[0][0];
        // return find(0,0,n,m,grid,dp);

        
    }
};