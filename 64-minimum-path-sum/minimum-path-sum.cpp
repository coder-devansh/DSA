class Solution {
public:
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
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return find(0,0,n,m,grid,dp);

        
    }
};