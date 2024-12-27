class Solution {
public:
vector<int>dp;
vector<int>dp1;
int fun1(int n,vector<int>&nums){
    if(n==0){
        return nums[0];
    }
     if(n<0){
        return 0;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    
    int pick=nums[n]+fun1(n-2,nums);
    int notpick=fun1(n-1,nums);
    return dp[n]=max(pick,notpick);
}
int fun(int n,vector<int>&nums){
      if(n==1){
        return nums[1];
    }
    if(n<1){
        return 0;
    }
    if(dp1[n]!=-1){
        return dp1[n];
    }
  
    int pick=nums[n]+fun(n-2,nums);
    int notpick=fun(n-1,nums);
    return dp1[n]=max(pick,notpick);
}
    int rob(vector<int>& nums) {
        if(nums.size()==0){
            return 0;

        }
        if(nums.size()==1){
            return nums[0];
        }
      dp.resize(nums.size(),-1);
      int left= fun1(nums.size()-2,nums);
      dp1.resize(nums.size(),-1); 
      int right= fun(nums.size()-1,nums);
       return max(left,right);       

    }
};