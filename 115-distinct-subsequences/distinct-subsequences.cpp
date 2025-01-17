class Solution {
public:
int find(string s,string t,int i,int j){
if(j<0){
    return 1;
}
if(i<0){
    return 0;
}
  if(s[i]==t[j])
  {
    int choice1=find(s,t,i-1,j-1);
    int choice2=find(s,t,i-1,j);
    return choice1+choice2;
  }else{
    return find(s,t,i-1,j);

  }
  
}
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,0));
        int n=s.size();
        int m=t.size();
        for(int j=0;j<=t.size();j++){
            dp[0][j]=0;
        }
        for(int i=0;i<=s.size();i++){
            dp[i][0]=1;
                    }
                    int mod=1e9+7;
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=t.size();j++){
                if(s[i-1]==t[j-1])
                {
                    int choice1=dp[i-1][j-1];
                    int choice2=dp[i-1][j];
                    dp[i][j]=(choice1+choice2)%mod;
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][m];
        
    }
};