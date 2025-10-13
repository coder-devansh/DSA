class Solution {
public:
unordered_set<string>st;
// void unique(int i, int j,int m,int n,string str){
//     if(i>=m || j>=n)return 0;
//     if(i==m-1 && j==n-1){
//         st.insert(str);
//         return;
//     }
//     int down=unique(i+1,j,m,n,str+'D');
//     int right=unique(i,j+1,m,n,str+'R');

// }
    int uniquePaths(int m, int n) {
        //  unique(0,0,m,n,"");
         vector<vector<int>>dp(m+1,vector<int>(n+1,0));
         dp[m-1][n-1]=1;
         for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int down=dp[i+1][j];
                int right=dp[i][j+1];
                dp[i][j]+=down+right;
            }
         }
         return dp[0][0];
        
    }
};