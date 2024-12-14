class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        map<int,int>mp;
        int r=0;
        int l=0;
        long long total=0;
        while(r<nums.size()){
            mp[nums[r]]++;
             while (!mp.empty() && (mp.rbegin()->first - mp.begin()->first > 2)) {
        
            mp[nums[l]]--;
            if (mp[nums[l]] == 0) {
                mp.erase(nums[l]);
            }
            l++;
        }
      total+=r-l+1;
       r++;
        }
        return total;
        
    }
};