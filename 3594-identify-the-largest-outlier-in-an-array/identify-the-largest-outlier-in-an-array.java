class Solution {
    public int getLargestOutlier(int[] nums) {
        HashMap<Integer,Integer>mp=new HashMap<>();
        int sum=0;

       for(int i=0;i<nums.length;i++){
        mp.put(nums[i],i);
        sum+=nums[i];
       }

       int maxi = Integer.MIN_VALUE;
       for(int i=0;i<nums.length;i++){
        int value=(sum-nums[i]);
        if(value % 2==0){
            value=value/2;
            if(mp.containsKey(value) && mp.get(value)!=i)
        {
            maxi=Math.max(maxi,nums[i]);
        }
        }
        

       }
       return maxi;
        
    }
}