class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int right=0;
        int left=0;
        map<int,int>mp;
        int maxi=INT_MIN;
        while(right<nums.size()){
            mp[nums[right]]++;
            while(mp[0]>k){
                mp[nums[left]]--;
                if(mp[nums[left]]==0)mp.erase(nums[left]);
                left++;
            }
            maxi=max(maxi,right-left+1);
            right++;
        }
        return maxi;

        
    }   
};