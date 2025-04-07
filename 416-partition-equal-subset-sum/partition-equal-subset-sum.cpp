class Solution {
public:
vector<vector<int >>dp;
bool helper(int i,vector<int>&nums,int sum,int target){
    if(sum==target/2) return true;
    if(i==nums.size()){
        if(sum==target/2) return true;
        return false;
    }
    if(dp[i][sum]!=-1) return dp[i][sum];
    bool left=helper(i+1,nums,sum+nums[i],target);
    bool right=helper(i+1,nums,sum,target);
    return dp[i][sum]=left || right;
}
    bool canPartition(vector<int>& nums) {
        long long sum=0;
        for(auto it:nums) sum+=it;
        if(sum%2!=0) return false;
        dp.resize(nums.size()+1,vector<int>(sum,-1));
        return helper(0,nums,0,sum);

        
    }
};