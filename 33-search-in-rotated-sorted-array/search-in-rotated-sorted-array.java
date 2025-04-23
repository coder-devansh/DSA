class Solution {
    int bs_search(int []arr,int x){
        
        int low=0;
        int high=arr.length-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]==x){
                return mid;
            }
            else if(arr[low]<=arr[mid]){
                if(arr[low]<=x && arr[mid]>=x){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
                
            }else{
                if(arr[mid]<=x && arr[high]>=x){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
        }
        return -1;
    }
    int search(int[] arr, int key) {
        return bs_search(arr,key);
        // Complete this function
    }
}