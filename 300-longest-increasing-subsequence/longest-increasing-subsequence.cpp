class Solution {
public:
int find_length(int i,int len,vector<int>&nums,int prev,vector<vector<int>>&dp){
 if(i==nums.size())return 0;
 if(dp[i][prev+1]!=-1)return dp[i][prev+1];
 int left=0;
    if(prev==-1 || nums[i]>nums[prev]){
        left=1+find_length(i+1,len,nums,i,dp);
    }
   int right=find_length(i+1,len,nums,prev,dp);

   return dp[i][prev+1]=max(left,right);
}
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));

       return find_length(0,0,nums,-1,dp);

       
        
    }
};