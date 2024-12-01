class Solution {
    public boolean checkIfExist(int[] nums) {
        HashMap<Integer,Integer>mp=new HashMap<>();
        for(int i=0;i<nums.length;i++){
            mp.put(nums[i],i);

        }
        for(int i=0;i<nums.length;i++){
            int value=nums[i]*2;
            if(mp.containsKey(value) && mp.get(value)!=i)
            {
                return true;
            }
        }
        return false;
        
    }
}