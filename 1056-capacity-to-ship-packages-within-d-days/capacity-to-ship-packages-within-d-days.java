class Solution {
    public static boolean cando(int capacity,int[]weights,int days){
        int c=0;
        int d=1;
        int i=0;
        for( i=0;i<weights.length;i++){
            if((c+weights[i])<=capacity){
                c+=weights[i];
            }else{
                d++;
                c=0;
                if(weights[i]<=capacity){
                     c+=weights[i];

                }else{
                    break;
                }
               
            }
            }
            if(i!=weights.length){
                return false;
            }
            if(d>days){
                return false;
            }
            return true;
    
    }
    public int shipWithinDays(int[] weights, int days) {
       
        int maxCapacity=0;
        for(int i=0;i<weights.length;i++){
               maxCapacity+=weights[i];
        }
        int left=0;
        int right=maxCapacity;
        while(left<right){
            int mid=(left+right)/2;
            if(cando(mid,weights,days))
            {
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return left;
        
    }
}