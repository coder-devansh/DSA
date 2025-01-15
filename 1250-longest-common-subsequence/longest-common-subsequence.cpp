class Solution {
public:
vector<vector<int>>dp;
int done(int i1,int i2,string text1,string text2){
    if(i1<0 || i2<0){
        return 0;
    }
    if(dp[i1][i2]!=-1){
        return dp[i1][i2];
    }
    if(text1[i1]==text2[i2]){
        return dp[i1][i2]=1+done(i1-1,i2-1,text1,text2);
    }
    return dp[i1][i2]=max(done(i1-1,i2,text1,text2),done(i1,i2-1,text1,text2));
}
    int longestCommonSubsequence(string text1, string text2) {
        dp.resize(text1.size()+1,vector<int>(text2.size()+1,0));

        
        for(int i=0;i<=text1.size();i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=text2.size();j++){
            dp[0][j]=0;
        }
        
        for(int i=1;i<=text1.size();i++){
            for(int j=1;j<=text2.size();j++){
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                     dp[i][j]=max(dp[i][j-1],dp[i-1][j]);

                }
               
            }
        }
        return dp[text1.size()][text2.size()];
        
        
    }
};