class Solution {
public:
long long find_money(int i,int n,vector<int>&nums,vector<int>&dp){
    if(i>n)return 0;
    if(dp[i]!=-1)return dp[i];
    long long take=nums[i]+find_money(i+2,n,nums,dp);
    long long not_take=find_money(i+1,n,nums,dp);
    return dp[i]=max(take,not_take);
}
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        if(nums.size()==2)return max(nums[0],nums[1]);
        int n=nums.size();
        vector<int>dp(n+1,-1);
        long long ans1=find_money(0,n-2,nums,dp);
        dp.assign(n+1,-1);
        long long ans2=find_money(1,n-1,nums,dp);
        return max(ans1,ans2);
        
    }
};