class Solution {
public:
    int minInsertions(string s) {
        string rev="";
        for(int i=s.size()-1;i>=0;i--){
            rev+=s[i];
        }
        vector<vector<int>>dp(s.size()+1,vector<int>(rev.size()+1,0));
        for(int i=0;i<=s.size();i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=rev.size();j++){
            dp[0][j]=0;
        }
        int n=s.size();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==rev[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }

            }

        }
        return n-dp[n][n];

    }
};