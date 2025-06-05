class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=INT_MAX;
        int sell=0;
        int max_profit=0;
        for(int i=0;i<prices.size();i++){
            if(buy!=INT_MAX){
                sell=max(prices[i],sell);
            }
            max_profit=max(max_profit,sell-buy);
            if(buy>prices[i]){
                
                buy=prices[i];
                sell=0;
            }


        }
        return max_profit;

        
    }
};