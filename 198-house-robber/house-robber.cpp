class Solution {
public:
int rob_house(int i,vector<int>&nums,vector<long long>&dp){
    if(i>=nums.size())return 0;
    if(dp[i]!=-1)return dp[i];
    long long take=nums[i]+rob_house(i+2,nums,dp);
    long long notTake=rob_house(i+1,nums,dp);
    return dp[i]=max(take,notTake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<long long>dp(n+1,-1);
        return rob_house(0,nums,dp);

        
        
    }
};