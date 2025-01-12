class Solution {
public:
int mod=1e9+7;
vector<vector<vector<int>>>dp;
long long  find(int i,int j,int k,int n,int m,vector<vector<int>>&coins){
    if(i==n-1 && j==m-1){
        if(k>0 && coins[i][j]<0){
            return 0;
        }
        return coins[i][j];
    }
    
  
    if(i>=n || j>=m){
        return INT_MIN;
    }
    if(dp[i][j][k]!=-1){
        return dp[i][j][k];
    }
    int taken=INT_MIN;
    int nottaken=INT_MIN;
    
    taken=coins[i][j]+max(find(i+1,j,k,n,m,coins),find(i,j+1,k,n,m,coins));
    if(coins[i][j]<0 && k>0){
        nottaken=max(find(i+1,j,k-1,n,m,coins),find(i,j+1,k-1,n,m,coins));
    }
    return dp[i][j][k]=max(taken,nottaken);

    }
    int maximumAmount(vector<vector<int>>& coins) {
        
       
       int n=coins.size();
       int m=coins[0].size();
       dp.resize(n+1,vector<vector<int>>(m+1,vector<int>(2+1,-1)));
       return find(0,0,2,n,m,coins);
        
    }
};