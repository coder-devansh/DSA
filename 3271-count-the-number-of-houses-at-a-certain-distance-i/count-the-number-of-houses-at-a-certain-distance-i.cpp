class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,1e9));
        for(int i=1;i<=n;i++){
            dp[i][i]=0;
        }
         for(int i=1;i<=n-1;i++){
           dp[i][i+1]=1;
           dp[i+1][i]=1;
        }
        dp[x][y]=1;
        dp[y][x]=1;

        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }
        vector<int>res(n,0);
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(dp[i][j]>0){
                    res[dp[i][j]-1]++;
                }
            }
            for(int k=1;k<i;k++){
                if(dp[i][k]>0){
                    res[dp[i][k]-1]++;
                }
            }
        }
        return res;
        
        

    }
};