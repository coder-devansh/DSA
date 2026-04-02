#define ll long long
class Solution {
public:
vector<vector<vector<ll>>>dp;
ll find(int i,int j,vector<vector<int>>&coins,int neutral){
    if(i==coins.size()-1 && j==coins[0].size()-1){
        if(coins[i][j]>=0)return coins[i][j];
        if(coins[i][j]<0 && neutral>0)return 0;
        return -abs(coins[i][j]);
    }
    if(i>=coins.size() || j>=coins[0].size())return INT_MIN;
    if(dp[i][j][neutral]!=-1)return dp[i][j][neutral];
    ll left=0;
    ll right=0;
    if(coins[i][j]>=0){
        left=coins[i][j]+find(i+1,j,coins,neutral);
        right=coins[i][j]+find(i,j+1,coins,neutral);
    }
    if(coins[i][j]<0){
        if(neutral>0){
            left=max(find(i+1,j,coins,neutral-1),-abs(coins[i][j])+find(i+1,j,coins,neutral));
            right=max(find(i,j+1,coins,neutral-1),-abs(coins[i][j])+find(i,j+1,coins,neutral));

        }else{
            left=-abs(coins[i][j])+find(i+1,j,coins,neutral);
            right=-abs(coins[i][j])+find(i,j+1,coins,neutral);
        }
        

    }
    return dp[i][j][neutral]=max(left,right);
}
    int maximumAmount(vector<vector<int>>& coins) {
        int n=coins.size();
        int m=coins[0].size();
        dp.resize(coins.size()+1,vector<vector<ll>>(coins[0].size()+1,vector<ll>(3,INT_MIN)));
        

int val=coins[n-1][m-1];
if(coins[n-1][m-1]>=0){
    dp[n-1][m-1][0]=val;
    dp[n-1][m-1][1]=val;
    dp[n-1][m-1][2]=val;
}
if(coins[n-1][m-1]<0){
    dp[n-1][m-1][0]=val;
    dp[n-1][m-1][1]=0;
    dp[n-1][m-1][2]=0;
}
for(int i=n-1;i>=0;i--){
    for(int j=m-1;j>=0;j--){
        for(int neutral=0;neutral<=2;neutral++){
            if(i==n-1 && j==m-1)continue;
            ll left=0;
            ll right=0;
            if(coins[i][j]>=0){
                 left=coins[i][j]+dp[i+1][j][neutral];
                 right=coins[i][j]+dp[i][j+1][neutral];
                
            }
            if(coins[i][j]<0){
                if(neutral>0){
                left=max(dp[i+1][j][neutral-1],coins[i][j]+dp[i+1][j][neutral]);
                right=max(dp[i][j+1][neutral-1],coins[i][j]+dp[i][j+1][neutral]);
                }
                else{
                    left=coins[i][j]+dp[i+1][j][neutral];
                    right=coins[i][j]+dp[i][j+1][neutral];
                }
            }
            dp[i][j][neutral]=max(left,right);

        }
    }
}
ll maxi=LLONG_MIN;
for(int i=0;i<=2;i++){
    maxi=max(maxi,dp[0][0][i]);
}
return maxi;
        
    }
};