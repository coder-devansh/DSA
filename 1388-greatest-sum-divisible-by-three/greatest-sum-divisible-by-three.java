class Solution {
    int find(int i,int []nums,int rem,int [][]dp){
        if(i>=nums.length){
            if(rem==0){
                return 0;
            }
            return Integer.MIN_VALUE;
        }
        if(dp[i][rem]!=-1)return dp[i][rem];
        int take=nums[i]+find(i+1,nums,(rem+nums[i])%3,dp);
        int skip=find(i+1,nums,rem,dp);
        return dp[i][rem]=Math.max(take,skip);
    }
    public int maxSumDivThree(int[] nums) {
        int dp[][]=new int[nums.length+1][3];
        for(int i=0;i<=nums.length;i++){
            Arrays.fill(dp[i],Integer.MIN_VALUE);
        }
        dp[nums.length][0]=0;
        for(int i=nums.length-1;i>=0;i--){
            for(int rem=0;rem<=2;rem++){
                int new_rem=((rem+nums[i]))%3;
int take=dp[i+1][new_rem]==Integer.MIN_VALUE?Integer.MIN_VALUE:nums[i]+dp[i+1][new_rem];
int skip=dp[i+1][rem];
dp[i][rem]=Math.max(take,skip);
            }
        }
        return dp[0][0];
        
    }
    
}