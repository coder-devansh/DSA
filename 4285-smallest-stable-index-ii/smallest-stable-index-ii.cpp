class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int>prefix(nums.size(),0);
        vector<int>suffix_minimum(nums.size(),0);
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i]=max(nums[i],prefix[i-1]);
        }
        suffix_minimum[nums.size()-1]=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            suffix_minimum[i]=min(suffix_minimum[i+1],nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            int val=prefix[i]-suffix_minimum[i];
            if(val<=k)return i;
        }
        return -1;



        
    }
};