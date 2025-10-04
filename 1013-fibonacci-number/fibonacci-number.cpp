class Solution {
public:
    int fib(int n) {
        if(n==0)return 0;
        if(n==1)return 1;
        vector<int>dp(n+1,0);
        dp[0]=0;
        dp[1]=1;
        int i=2;
        while(i<=n){
            dp[i]=dp[i-1]+dp[i-2];
            i++;
        }
        return dp[n];
        
    }
};