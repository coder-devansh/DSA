#define ll long long
class Solution {
public:
int find_max(int i,int k,vector<int>&arr){
    int maxi=0;
    for(int j=i;j<=k;j++){
        maxi=max(maxi,arr[j]);

    }
    return maxi;
}
vector<vector<ll>>dp;
ll find(int i,int j,vector<int>&arr){
    if(i>=j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    ll mini=INT_MAX;
    for(int k=i;k<j;k++){
        ll ans1=find(i,k,arr);
        ll ans2=find(k+1,j,arr);
        mini=min(mini,find_max(i,k,arr)*find_max(k+1,j,arr)+ans1+ans2);

    }
    return dp[i][j]=mini;
}
    int mctFromLeafValues(vector<int>& arr) {
        dp.resize(arr.size(),vector<ll>(arr.size(),-1));
       return find(0,arr.size()-1,arr);
        
    }
};