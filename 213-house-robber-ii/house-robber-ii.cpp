class Solution {
public:
int amount_stolen(int i,int n,vector<int>&nums,vector<int>&dp){
    if(i>=n){
        return 0;
    }
    if(dp[i]!=-1)return dp[i];


    int stolen_money=nums[i]+amount_stolen(i+2,n,nums,dp);
    int not_pick=amount_stolen(i+1,n,nums,dp);

    return dp[i]=max(stolen_money,not_pick);


}
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        nums.push_back(nums[0]);
        int n=nums.size();
        vector<int>dp1(nums.size()+1,-1);
         int amount_1=amount_stolen(1,n-1,nums,dp1);
         vector<int>dp2(nums.size()+1,-1);
         int amount_2=amount_stolen(2,n,nums,dp2);
         return max(amount_1,amount_2);

        
    }
};