class Solution {
public:
int find(vector<int>&nums,int k){
    int left=0;
    int right=0;
    map<int,int>mp;
    int count1=0;
    while(right<nums.size()){
        mp[nums[right]]++;
        while(left<=right && mp.size()>k){
            mp[nums[left]]--;
            if(mp[nums[left]]==0)mp.erase(nums[left]);
            left++;
        }
       
            count1+=(right-left+1);
        
        right++;

    }
    return count1;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return find(nums,k)-find(nums,k-1);
        
    }
};