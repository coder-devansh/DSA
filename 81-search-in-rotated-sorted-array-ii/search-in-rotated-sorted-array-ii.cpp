class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int start=0;
        int end=arr.size()-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(arr[mid]==target) return true;
            if(arr[start]==arr[end]){
                if(arr[start]==target)  return true;
                start++;
                end--;
            }
            else if(arr[start]<=arr[mid])
            {
                
                if(arr[start]<=target && target<=arr[mid]){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
            else{
                
                if(arr[mid]<=target && target<=arr[end]){
                    start=mid+1;
                }else{
                    end=mid-1;
                }
            }
        }
        return false;
        
    }
};