class Solution {
    public int[] resultsArray(int[] nums, int k) {
        
        int l=0;
        int r=1;
     
        int n=nums.length;
        int []arr=new int[n-k+1];
        if(k==1){
            return nums;
        }
        if(k==2){

        }
        if(k==1 && nums.length==1){
            arr[0]=nums[0];
            return arr;
        }
        for(int i=0;i<=nums.length-k;i++){
            r=i;
            int index=r+k;
            int count=0;
            
            int maxi=0;
            int found=0;
            while(r<index-1)
            {

                if((nums[r+1]-nums[r])==1){
                     maxi=Math.max(maxi,nums[r+1]);

                }
                else{
                    found=1;
                }
              
                r++;
            }
            if(maxi>0 && found==0){
                arr[i]=maxi;
            }
            else{
                arr[i]=-1;
            }
            
         
          
        }
        return arr;
    }
}