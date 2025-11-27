class Solution {
    public long maxSubarraySum(int[] nums, int k) {
        
        long  prefix_sum[]=new long[nums.length+1];
        prefix_sum[0]=nums[0];
        for(int i=1;i<nums.length;i++){
            prefix_sum[i]=prefix_sum[i-1]+nums[i];
        }
        long max_sum = Long.MIN_VALUE;
       
        int n=nums.length;
        for(int start=0;start<k;start++){
            int i=start;
             long curr_sum=0;
            while(i<n && i+k-1<n){
                int j=i+k-1;
long sub_sum=(i==0)?prefix_sum[j]:prefix_sum[j]-prefix_sum[i-1];
                curr_sum=Math.max(sub_sum,curr_sum+sub_sum);
                max_sum=Math.max(max_sum,curr_sum);
                i=i+k;
            }
        }
        return max_sum;

        
        
    }
}