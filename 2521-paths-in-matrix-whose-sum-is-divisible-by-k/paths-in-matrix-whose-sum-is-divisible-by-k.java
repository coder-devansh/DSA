class Solution {
    static int mod=(int)1e9+7;
    public static int find(int i,int j,int n,int m,int [][]grid,int rem,int k,int [][][]dp){
        if(i>=n || j>=m)return 0;
        if(i==n-1 && j==m-1){
            if((rem+grid[i][j])%k==0)return 1;
            return 0;
        }
        if(dp[i][j][rem]!=-1)return dp[i][j][rem];
        int left=find(i+1,j,n,m,grid,(rem+grid[i][j])%k,k,dp);
        int right=find(i,j+1,n,m,grid,(rem+grid[i][j])%k,k,dp);
        return dp[i][j][rem]=(left+right)%mod;
    }
    public int numberOfPaths(int[][] grid, int k) {
        int n=grid.length;
        int m=grid[0].length;
        int [][][]dp=new int[n+1][m+1][k+1];
        for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        for (int x= 0; x<=k; x++) {
            dp[i][j][x] =-1; // calculate value
        }
    }
}
return find(0,0,n,m,grid,0,k,dp);

        
    }
}