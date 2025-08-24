class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        map<int,int>mp;
        for(auto it:nums)mp[it]++;
        if(nums.size() % k!=0)return false;
        int total_group=nums.size()/k;
        for(auto it:mp){
            if(mp[it.first]>total_group)return false;
        }
        return true;

        
    }
};