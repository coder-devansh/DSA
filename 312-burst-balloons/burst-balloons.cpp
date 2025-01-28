class Solution {
public:
vector<vector<int>>dp;
int find(vector<int>&nums,int i,int j){
    if(i>=j)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
{
    return dp[i][j];
}    int maxi=INT_MIN;
    for(int k=i;k<j;k++){
        int total=nums[i-1]*nums[k]*nums[j]+find(nums,i,k)+find(nums,k+1,j);
        maxi=max(maxi,total);
    }
    return dp[i][j]=maxi;
}
    int maxCoins(vector<int>& nums) {
        vector<int>ans(nums.size()+2,0);
        ans[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            ans[i+1]=nums[i];
        }
        ans[nums.size()+1]=1;
        dp.resize(ans.size(),vector<int>(ans.size(),-1));
        
        
        return find(ans,1,ans.size()-1);
        
    }
};