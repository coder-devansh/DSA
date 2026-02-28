#define ll long long
#define vi vector<int>
class Solution {
public:
bool find(vector<int>&nums,int k,int mask,int target,ll sum,vector<int>&dp){
    if(k==0)return true;
    if(sum==target){
        return find(nums,k-1,mask,target,0,dp);
    }
    if(dp[mask]!=-1)return dp[mask];
    for(int i=0;i<nums.size();i++){
        if((mask & (1<<i))==0 && (sum+nums[i])<=target){
            if(find(nums,k,mask | (1<<i) ,target,sum+nums[i],dp)){
                return dp[mask]=1;
            }
        }
    }
    return dp[mask]=0;
}
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        ll sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%k!=0)return false;
        ll target=sum/k;
        vector<int>dp(1<<16,-1);
        return find(nums,k,0,target,0,dp);
        
    }
};