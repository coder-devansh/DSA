class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]==0 || mp[nums[i]+1]==0)continue;
            maxi=max(maxi,mp[nums[i]]+mp[nums[i]+1]);
        }
        return maxi;
        
    }
};