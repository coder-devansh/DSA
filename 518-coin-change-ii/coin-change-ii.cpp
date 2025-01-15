

class Solution {
public:
int mod=1e9+7;
// int find(int i,int amount,vector<int>&coins){
//     if(i==0){
//         return amount%coins[i]==0;
//     }
   
//     if(dp[i][amount]!=-1){
//         return dp[i][amount];
//     }
//     int take=0;
//     if(amount>=coins[i]){
//           take=find(i,amount-coins[i],coins);
//     }
   
//     int nottaken=find(i-1,amount,coins);
//     return dp[i][amount]=(take+nottaken);
// }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
      vector<vector<double >>dp(n,vector<double >(amount+1,0));
        for(int i=0;i<=amount;i++){
            if((i % coins[0])==0){
                dp[0][i]=1;
            }
            else{
                dp[0][i]=0;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                double  take=0;
                if(j>=coins[i])
                {
                    take=dp[i][j-coins[i]];
                }
                    double  nottaken=dp[i-1][j];
                dp[i][j]=(take+nottaken);
            }
        }
        return dp[n-1][amount];
        
    }
};