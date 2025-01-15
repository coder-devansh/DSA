

class Solution {
public:
vector<vector<int>>dp;
int mod=1e9+7;
int find(int i,int amount,vector<int>&coins){
    if(i==0){
        return amount%coins[i]==0;
    }
   
    if(dp[i][amount]!=-1){
        return dp[i][amount];
    }
    int take=0;
    if(amount>=coins[i]){
          take=find(i,amount-coins[i],coins);
    }
   
    int nottaken=find(i-1,amount,coins);
    return dp[i][amount]=(take+nottaken);
}
    int change(int amount, vector<int>& coins) {
        if(coins.size()==1 ){
            if(amount % coins[0]==0){
                return 1;
            }
        }
        if(amount==0){
            return 1;
        }
        dp.resize(coins.size(),vector<int>(50001,-1));

        
        int n=coins.size();
       return  find(n-1,amount,coins);
        
        
    }
};