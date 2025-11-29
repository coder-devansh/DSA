class Solution {
    public int maxSubarraySumCircular(int[] nums) {
        int max_sum=nums[0];
        int min_sum=nums[0];
        int curr_sum=nums[0];
        int curr_min=nums[0];
        int total=0;
        for(int i=1;i<nums.length;i++){
            curr_sum=Math.max(nums[i],curr_sum+nums[i]);
            max_sum=Math.max(max_sum,curr_sum);
            curr_min=Math.min(nums[i],curr_min+nums[i]);
            min_sum=Math.min(min_sum,curr_min);
            total+=nums[i];
            
        }
        total+=nums[0];

        return max_sum<0?max_sum:Math.max(max_sum,total-min_sum);
        
    }
}