class Solution {
public:

int dfs(int row,int col,int n,int m,vector<vector<int>>&matrix,vector<vector<int>>&dp){
    int max_pathlength=1;
    if(dp[row][col]!=-1)
    {
        return dp[row][col];
    }
    int r[]={-1,0,1,0};
    int c[]={0,1,0,-1};
    for(int i=0;i<4;i++)
    {
        int rows=row+r[i];
        int column=col+c[i];
        if(rows>=0 && rows<n && column>=0 && column<m && matrix[row][col]<matrix[rows][column])
        {
            
           
                 max_pathlength=max(max_pathlength,1+dfs(rows,column,n,m,matrix,dp));

           

        }
    }
    dp[row][col]=max_pathlength;
    return dp[row][col];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>>dp(matrix.size()+234,vector<int>(matrix[0].size()+345,-1));
        
        int n=matrix.size();
        int m=matrix[0].size();
        int max_path=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(dp[i][j]==-1){
                
                    max_path=max(max_path,dfs(i,j,n,m,matrix,dp));


                }
                
                    
                
                

            }
        }
        return max_path;
        
    }
};