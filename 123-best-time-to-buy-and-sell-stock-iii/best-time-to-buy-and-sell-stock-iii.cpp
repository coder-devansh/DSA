class Solution {
public:
int max_profit(int i,vector<int>&prices,int buy,int allowed, vector<vector<vector<int>>>&dp){
    if(i==prices.size())return 0;
    if(allowed==2)return 0;
    if(dp[i][buy][allowed]!=-1)return dp[i][buy][allowed];
   long long profit=0;
    if(buy){
        profit=max(-prices[i]+max_profit(i+1,prices,0,allowed,dp),max_profit(i+1,prices,1,allowed,dp));

    }
    if(!buy){
        profit=max(prices[i]+max_profit(i+1,prices,1,allowed+1,dp),max_profit(i+1,prices,0,allowed,dp));
    }
    return dp[i][buy][allowed]=profit;
}
    int maxProfit(vector<int>& prices) 
    {
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        return max_profit(0,prices,1,0,dp);
        
    }
};