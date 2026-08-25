class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        map<int,int>mp;
        for(auto it:nums)mp[it]++;
        int l=1;
        while(true){
            long long val=k*l;
            if(mp.find(val)==mp.end())return val;
            l++;

        }
        return 0;

        
    }
};