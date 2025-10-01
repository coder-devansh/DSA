class Solution {
public:
int find(int n,int k,vector<int>&dp)
{
    
    if(n==0 && k>=2){
        return 1;
    }
    if(dp[n]!=-1)return dp[n];
    int maxi=0;
    for(int i=1;i<=n;i++){
        if(n>=i){
            int val=find(n-i,k+1,dp);
            maxi=max(maxi,i*val);


        }
       
    }
    return dp[n]=maxi;

}
    int integerBreak(int n) {
        vector<int>dp(n+1,-1);
        return find(n,0,dp);

        
    }
};