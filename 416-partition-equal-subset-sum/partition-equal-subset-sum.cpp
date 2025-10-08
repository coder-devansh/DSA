class Solution {
public:
bool can(int i,int target,vector<int>&nums,vector<vector<int>>&dp){
    if(target<0)return false;
    if(i==nums.size()){
        return target==0;
    }
    if(dp[i][target]!=-1)return dp[i][target];
    bool include=can(i+1,target-nums[i],nums,dp);
    bool exclude=can(i+1,target,nums,dp);
    return dp[i][target]=include || exclude;
}
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0)return false;
        int t=sum/2;
        vector<vector<int>>dp(nums.size()+1,vector<int>(t+1,0));
        dp[nums.size()][0]=1;
        // return can(0,target,nums,dp);
        for(int i=nums.size()-1;i>=0;i--){
            for(int target=0;target<=t;target++){
                if(nums[i]<=target){
                    int pick=dp[i+1][target-nums[i]];
                    int not_pick=dp[i+1][target];
                    dp[i][target]=pick || not_pick;
                }else{
                    dp[i][target]=dp[i+1][target];
                }
            }
        }
        
        return dp[0][t];


        
    }
};