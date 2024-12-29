class Solution {
public:
int mod=1000000007;
int dp[1001][1001];
long long  solve(int i,int j,vector<vector<long long>>&freq,string&target,int m){
    if(i==target.size()){
        return 1;
    }
    if(j==m){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    long long  taken=(freq[target[i]-'a'][j]*solve(i+1,j+1,freq,target,m))%mod;
    long long nottaken=(solve(i,j+1,freq,target,m))%mod;
    return dp[i][j]=(taken+nottaken)%mod;
}
    int numWays(vector<string>& words, string target) {
        vector<vector<long long >>freq(26,vector<long long >(words[0].size(),0));
        for(int col=0;col<words[0].size();col++){
            for(auto it:words){
                char ch=it[col];
                freq[ch-'a'][col]++;
            }

        }
memset(dp,-1,sizeof(dp));      
        return solve(0,0,freq,target,words[0].size());
      
     
       
       
        
    }
};