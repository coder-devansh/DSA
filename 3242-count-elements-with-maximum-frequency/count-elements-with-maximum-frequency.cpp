class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int>mp;
        int maxi=0;
        for(auto it:nums){
            mp[it]++;
            maxi=max(maxi,mp[it]);

        }
        long long count=0;
        for(auto it:mp){
            if(it.second==maxi)count+=it.second;
        }
        return count;
        
    }
};