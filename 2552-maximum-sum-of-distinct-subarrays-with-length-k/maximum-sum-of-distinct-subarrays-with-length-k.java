class Solution {
    public long maximumSubarraySum(int[] nums, int k) {
        long sum=0;
        long mod=1000000007;
        long currentsum=0;
        HashMap<Integer,Integer>mp=new HashMap<>();
    for(int i=0;i<nums.length;i++){

        mp.put(nums[i],mp.getOrDefault(nums[i],0)+1);
        currentsum+=nums[i];

        if(i>=k)
        {
            int leftsum=nums[i-k];
            currentsum-=nums[i-k];
            mp.put(leftsum,mp.get(leftsum)-1);

            if(mp.get(leftsum)==0){
                mp.remove(leftsum);
            }

        }

        if(i>=k-1 && mp.size()==k)
        {
            sum=Math.max(sum,currentsum);
        }
           


        }
        return sum;

        
    }
}