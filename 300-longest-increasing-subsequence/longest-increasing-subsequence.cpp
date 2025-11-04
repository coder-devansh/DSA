class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>arr(nums.size(),1);
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(arr[i]<=arr[j]){
                        arr[i]=arr[j]+1;
                    }
                    
                }
            }
            maxi=max(maxi,arr[i]);
        }
        return maxi;

        
        
        
    }
};