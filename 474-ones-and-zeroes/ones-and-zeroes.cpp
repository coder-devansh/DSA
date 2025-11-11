class Solution {
public:
int find(int i,vector<pair<int,int>>&vec,int m,int n,vector<vector<vector<int>>>&dp){
    if(m<=0 && n<=0)return 0;
    if(i>=vec.size())return 0;
    if(dp[i][m][n]!=-1)return dp[i][m][n];
    int maxi=0;
    if(m>=vec[i].first && n>=vec[i].second){
       int left=1+find(i+1,vec,m-vec[i].first,n-vec[i].second,dp);
        int right=find(i+1,vec,m,n,dp);
        maxi=max(left,right);
    }
   maxi=max(maxi,find(i+1,vec,m,n,dp));
   return dp[i][m][n]=maxi;

}
    int findMaxForm(vector<string>& strs, int m, int n) {
      vector<pair<int,int>>vec;
      for(int i=0;i<strs.size();i++){
        string str=strs[i];
        map<int,int>mp;
        for(auto it:str){
            mp[it-'0']++;
        }
        vec.push_back({mp[0],mp[1]});
      }
      vector<vector<vector<int>>>dp(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
      int val=find(0,vec,m,n,dp);
      if(val==INT_MIN){
        return 0;
      }
      return val;
        
    }
};