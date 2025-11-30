class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum=0;
        for(auto it:nums){
            sum=(sum+it)%p;

        }

        if(sum==0)return 0;
        int target=sum;
        map<int,int>mp;
        int mini=INT_MAX;
        sum=0;
        mp[0] = -1;
        for(int i=0;i<nums.size();i++){
            sum=(sum+nums[i])%p;
            if(mp.find((sum-target+p)%p)!=mp.end())
            {
                mini=min(mini,i-mp[(sum-target+p)%p]);
            }
            mp[sum]=i;

        }
        if(mini==INT_MAX || mini==nums.size())return -1;
        return mini;
        
    }
};