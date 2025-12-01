class Solution {
    public boolean increasingTriplet(int[] nums) {
        int n=nums.length;
        int prefix[]=new int[n+1];
        int suffix[]=new int[n+1];
        prefix[0]=nums[0];
        for(int i=1;i<nums.length;i++){
           prefix[i]=Math.min(prefix[i-1],nums[i]);
        }
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=Math.max(suffix[i+1],nums[i]);

        }
        for(int i=1;i<n-1;i++){
            if(prefix[i-1]<nums[i] && nums[i]<suffix[i+1]){
                return true;
            }
        }
        return false;


        
        
    }
}