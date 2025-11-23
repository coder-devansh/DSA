class Solution {

    public int maxSumDivThree(int[] nums) {
       ArrayList<Integer>rem_1=new ArrayList<>();
       ArrayList<Integer>rem_2=new ArrayList<>();
       int sum=0;   
       for(int i=0;i<nums.length;i++){
            sum+=nums[i];
            if(nums[i]%3==1){
                rem_1.add(nums[i]);
            }else if(nums[i]%3==2){
                rem_2.add(nums[i]);

            }


       }
       if(sum%3==0){
        return sum;
       }
       Collections.sort(rem_1);
       Collections.sort(rem_2);
       int maxi=0;
       int rem=sum%3;
       if(rem==1){
        int val1=Integer.MAX_VALUE;
        int val2=Integer.MAX_VALUE;
          if(rem_1.size()>0){
             val1=rem_1.get(0);
          }if(rem_2.size()>=2){
             val2=rem_2.get(0)+rem_2.get(1);
          }
          maxi=Math.max(maxi,sum-Math.min(val1,val2));
          return maxi;

       }
       if(rem==2){
        int val1=Integer.MAX_VALUE;
        int val2=Integer.MAX_VALUE;
        if(rem_2.size()>0){
            val1=rem_2.get(0);
        }
        if(rem_1.size()>=2){
            val2=rem_1.get(0)+rem_1.get(1);
        }
        maxi=Math.max(maxi,sum-Math.min(val1,val2));
        return maxi;
       }
       return maxi;
       

        
    }
}