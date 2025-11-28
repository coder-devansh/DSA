class Solution {
    public boolean canbe(int mid,int citations[]){
        int count=0;
        for(int i=0;i<citations.length;i++){
            if(citations[i]>=mid){
                count++;
                if(count>=mid)return true;
            }
        }
        return false;
    }
    public int hIndex(int[] citations) {
        int n=citations.length;
        int low=1;
        int high=citations[n-1];
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(canbe(mid,citations)){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }

        }
        if(ans==-1)return 1;
        return ans;



        
    }
}