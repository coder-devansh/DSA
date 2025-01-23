class Solution {
public:
vector<vector<vector<int>>>dp;
int find(vector<int>&prices,int buy,int limit,int index){
if(index==prices.size()){
    return 0;
}
if(dp[index][buy][limit]!=-1){
    return dp[index][buy][limit];
}
int profit=0;
    if(buy && limit>0){
        int buy=-prices[index]+find(prices,0,limit,index+1);
        int not_buy=0+find(prices,1,limit,index+1);
        profit=max(buy,not_buy);
    }else if(limit>0){
        int sell=prices[index]+find(prices,1,limit-1,index+1);
        int not_sell=find(prices,0,limit,index+1);
        profit=max(sell,not_sell);

    }
    return dp[index][buy][limit]=profit;
}
    int maxProfit(int k,vector<int>& prices) {
     dp.resize(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
        return  find(prices,1,k,0);
        
    }
};