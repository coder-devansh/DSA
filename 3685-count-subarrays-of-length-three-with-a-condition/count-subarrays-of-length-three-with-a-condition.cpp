class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count=0;
        for(int i=0;i<=nums.size()-3;i++){
           
            int sum=nums[i]+nums[i+2];
            if(2*sum==nums[i+1])count++;
           
        }
        return count;

        
    }
};