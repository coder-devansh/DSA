class Solution {
    public List<Boolean> prefixesDivBy5(int[] nums) {
        long curr_num=0;
        ArrayList<Boolean>ans=new ArrayList<>();
        for(int i=0;i<nums.length;i++){
            if(nums[i]==1)
            {
                curr_num+=1*Math.pow(2,(nums.length-i-1)%32);
                if(curr_num%5==0){
                    ans.add(true);

                }else{
                    ans.add(false); 
                }
                
            }
            else{
                if(curr_num%5==0){
                    ans.add(true);

                }else{
                    ans.add(false);
                }

            }
        }
        return ans;

        
        
    }
}