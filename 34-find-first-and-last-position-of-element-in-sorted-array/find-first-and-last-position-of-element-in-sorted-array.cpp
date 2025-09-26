class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        int low=0;
        int high=nums.size()-1;
        int first=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                first=mid;
                high=mid-1;
            }if(nums[mid]>=target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        low=0;
        high=nums.size()-1;
        int last=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                last=mid;
            }if(nums[mid]<=target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return {first,last};
        
        
    }
};