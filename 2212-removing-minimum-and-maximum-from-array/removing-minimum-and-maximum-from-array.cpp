class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int min_value=INT_MAX;
        int max_value=INT_MIN;
        int min_index=-1;
        int max_index=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<min_value){
                min_index=i;
                min_value=nums[i];
            }
            if(nums[i]>max_value){
                max_index=i;
                max_value=nums[i];
            }
        }
        int large=max(min_index,max_index);
        int small=min(min_index,max_index);
        return min({large+1,(int)nums.size()-small,small+1+((int)nums.size()-large)});
        
    }
};