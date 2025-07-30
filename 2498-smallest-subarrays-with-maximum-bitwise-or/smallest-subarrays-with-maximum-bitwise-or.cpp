class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> ans(nums.size());
      for(int i =0;i < nums.size(); i++) {
        int x = nums[i];
        ans[i]=1;
        for(int j = i - 1; j >= 0 && (x | nums[j]) != nums[j]; j--) {
            nums[j] |= x;
            ans[j] = i - j + 1;
        }
      }
      return ans;
        
    }
};