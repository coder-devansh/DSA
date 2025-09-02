class Solution {
public:
int max_profit(int i,vector<int>&prices,int buy, vector<vector<int>>&dp){
    if(i>=prices.size())return 0;
    
    if(dp[i][buy]!=-1)return dp[i][buy];
   long long profit=0;
    if(buy){
        profit=max(-prices[i]+max_profit(i+1,prices,0,dp),max_profit(i+1,prices,1,dp));

    }
    if(!buy){
        profit=max(prices[i]+max_profit(i+2,prices,1,dp),max_profit(i+1,prices,0,dp));
    }
    return dp[i][buy]=profit;
}
    int maxProfit(vector<int>& prices) 
    {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return max_profit(0,prices,1,dp);
        
    }
};