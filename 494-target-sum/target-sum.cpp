class Solution {
public:
int find(vector<int>arr,int target,int i){
    vector<vector<int>>dp(arr.size(),vector<int>(target+1,0));
    if(arr[0]==0){
        dp[0][0]=2;
    }
    else{
        dp[0][0]=1;
    }
    if(arr[0]!=0 && arr[0]<=target){
        dp[0][arr[0]]=1;
    }
    for(int i=1;i<arr.size();i++){
        for(int tar=0;tar<=target;tar++){
            int nottaken=dp[i-1][tar];
            int taken=0;
            if(arr[i]<=tar){
                taken=dp[i-1][tar-arr[i]];

            }
            dp[i][tar]=nottaken+taken;
        }
    }
    
   
   
    return dp[arr.size()-1][target];
   
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if((sum-target)<0 || (sum-target)%2!=0){
            return 0;
        }
       return find(nums,(sum-target)/2,nums.size()-1);
        
    }
};