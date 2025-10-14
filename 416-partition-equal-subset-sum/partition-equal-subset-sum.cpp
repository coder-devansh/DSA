class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        long long sum=accumulate(nums.begin(),nums.end(),0);
        if(sum % 2==1)return false;
        long long target=sum/2;
        vector<vector<int>>dp(n,vector<int>(sum+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=true;

        }
        if(nums[0]<=sum){
            dp[0][nums[0]]=true;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=target;j++){
                if(j-nums[i]<0){
                    dp[i][j]=dp[i-1][j];
                }else{
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-nums[i]];
                }

            }
        }
        return dp[n-1][target];
        
    }
};