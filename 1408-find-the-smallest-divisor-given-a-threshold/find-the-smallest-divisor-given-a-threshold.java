class Solution {
    public boolean canbe(int mid,int threshold,int nums[]){
        int sum=0;
        for(int i=0;i<nums.length;i++){
            sum+=Math.ceil(nums[i]*1.0/mid);
        }
        if(sum<=threshold)return true;
        return false;
    }
    public int smallestDivisor(int[] nums, int threshold) {
        int sum=0;
        int low=1;
        int high=(int)1e9;
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(canbe(mid,threshold,nums)){
                high=mid-1;
                ans=mid;
            }else{
               low=mid+1;
            }
        }
        return ans;
        
    }
}