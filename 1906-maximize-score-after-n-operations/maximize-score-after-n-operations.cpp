class Solution {
public:
int find_score(vector<int>&nums,int opr,int mask,vector<int>&dp){
    if(opr>nums.size()/2)return 0;
    if(dp[mask]!=-1)return dp[mask];
    for(int i=0;i<nums.size();i++){
        if(mask & (1<<i))continue;
        for(int j=i+1;j<nums.size();j++){
            if(mask & 1<<j)continue;
            int new_mask= mask | 1<<i | 1<<j;
            int score=opr * __gcd(nums[i],nums[j])+find_score(nums,opr+1,new_mask,dp);
            dp[mask]=max(score,dp[mask]);
        }
    }
    return dp[mask];
}
    int maxScore(vector<int>& nums) {
        vector<int>dp(1<<14,-1);
        return find_score(nums,1,0,dp);
        
    }
};