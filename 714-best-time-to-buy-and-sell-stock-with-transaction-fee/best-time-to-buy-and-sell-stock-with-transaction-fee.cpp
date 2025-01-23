class Solution {
public:
int data=0;
vector<vector<int>>dp;
int find(vector<int>&prices,int buy,int index){
if(index>=prices.size()){
    return 0;
}
if(dp[index][buy]!=-1){
    return dp[index][buy];
}
int profit=0;

    if(buy){
         int buy=-prices[index]+find(prices,0,index+1);
        int not_buy=0+find(prices,1,index+1);
        profit=max(buy,not_buy);
    }else{
         int sell=prices[index]-data+find(prices,1,index+1);
        int not_sell=find(prices,0,index+1);
        profit=max(sell,not_sell);

    }
    return dp[index][buy]=profit;
}
    int maxProfit(vector<int>& prices,int fee) {
        data=fee;
     dp.resize(prices.size(),vector<int>(2,-1));
        return  find(prices,1,0);
        
    }
};