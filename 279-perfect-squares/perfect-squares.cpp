class Solution {
public:
int min_number(int n,int count,vector<int>&dp){
    if(n==0){
        return 0;
    }
    if(dp[n]!=-1)return dp[n];
    int sum=0;
    int mini=INT_MAX;
    for(int i=1;i*i<=n;i++){
        if(n>=i*i){ 
            mini=min(mini,1+min_number(n-i*i,count,dp));
        }

    }
    return dp[n]=mini;

}
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return min_number(n,0,dp);
        
        
    }
};