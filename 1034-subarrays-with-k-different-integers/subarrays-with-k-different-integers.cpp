class Solution {
public:
int slidingWindowAtMost(vector<int>nums,int k){
     int right=0;
       int left=0;
       map<int,int>mp;
       int total_array=0;
       while(right<nums.size()){
        mp[nums[right]]++;
        while(left<right && mp.size()>k){
            mp[nums[left]]--;
            if(mp[nums[left]]==0)mp.erase(nums[left]);
            left++;
        }
        if(mp.size()<=k){
            total_array+=right-left+1;
        }
        right++;
       }
       return total_array; 
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return slidingWindowAtMost(nums,k)-slidingWindowAtMost(nums,k-1);
       



            


        
    }
};