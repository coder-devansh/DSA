class Solution {
public:
vector<vector<int>>dp;
int find(vector<int>&ans,int i,int j){
    if(i>j) return 0;
    int mini=1e9;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    for(int k=i;k<=j;k++){
        int  cuts_taken=ans[j+1]-ans[i-1]+find(ans,i,k-1)+find(ans,k+1,j);
        mini=min(mini,cuts_taken);
        
    }
    return dp[i][j]=mini;
}
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        vector<int>ans(cuts.size()+2,0);
        for(int i=0;i<cuts.size();i++){
            ans[i+1]=cuts[i];
        }
       
        ans[cuts.size()+1]=n;
        // for(auto it:ans){
        //     cout<<it<<" ";
        // }
        dp.resize(ans.size(),vector<int>(ans.size(),-1));
        return find(ans,1,ans.size()-2);
        return 0;
        
    }
};