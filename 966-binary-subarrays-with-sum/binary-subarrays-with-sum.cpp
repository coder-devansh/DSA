class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>prefix_sum;
        prefix_sum[0]=1;
        int sum=0;
        int count=0;
        for(auto it:nums){
            sum+=it;
            if(prefix_sum.find(sum-goal)!=prefix_sum.end())
            {
                count+=prefix_sum[sum-goal];
            }
            prefix_sum[sum]++;


        }
        return count;
        
    }
};