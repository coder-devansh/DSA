class Solution {
public:
vector<vector<long long >>dp;
int mod=1e9+7;
long long  find(int i,int target,int x,int dest){
   int power=pow(i,x);
   if(power>target){
    return 0;
   }
   if(power==target){
    return 1;
   }
   if(dp[i][target]!=-1){
    return dp[i][target];
   }
   
    int left=find(i+1,target-power,x,dest);
    int right=find(i+1,target,x,dest);
    return dp[i][target]=(left+right)%mod;
}
    int numberOfWays(int n, int x) {
        
        int dest=sqrt(n);
        dp.resize(n+3,vector<long long >(n+1,-1));
        return find(1,n,x,dest);
        
    }
};
