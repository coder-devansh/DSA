class Solution {
public:
vector<int>dp;
int fun(int n){
    if(n==0 || n==1)
    {
        return 1;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    return dp[n]=fun(n-1)+fun(n-2);
}
    int climbStairs(int n) {
        dp.resize(10001,-1);
        return fun(n);
    }
};