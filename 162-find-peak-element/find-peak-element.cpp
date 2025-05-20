class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int maxi=INT_MIN;
        int index=0;
        for(int i=nums.size()-1;i>=0;i--){
            if(maxi<nums[i]){
                maxi=nums[i];
                index=i;
            }
            
        }
        return index; 
        
    }
};