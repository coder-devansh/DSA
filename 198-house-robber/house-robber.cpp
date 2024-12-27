class Solution {
public:
vector<int>dp;
int fun(int n,vector<int>nums){
    if(n<0){
        return 0;
    }
    if(n==0){
        return nums[0];
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int pick=nums[n]+fun(n-2,nums);
    int notpick=fun(n-1,nums);
    return dp[n]=max(pick,notpick);

}
    int rob(vector<int>& nums) {
        dp.resize(nums.size(),-1);
        return fun(nums.size()-1,nums);
        
    }
};