class Solution {
public:
vector<vector<int>>dp;
int find(vector<int>&prices,int buy,int index){
    if(index==prices.size()){
        return 0;
    }
    int profit=0;
    if(dp[index][buy]!=-1){
        return dp[index][buy];
    }

    if(buy){
       int  buying=-prices[index]+find(prices,0,index+1);
        int nt_buy=find(prices,1,index+1);
        profit=max(buying,nt_buy);
    }
    else{
        int sell=prices[index]+find(prices,1,index+1);
        int not_sell=find(prices,0,index+1);
        profit=max(sell,not_sell);
    }
    return dp[index][buy]=profit;
}
    int maxProfit(vector<int>& prices) {
     dp.resize(prices.size(),vector<int>(2,-1));
        return find(prices,1,0);
        
    }
};