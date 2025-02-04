class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        long long sum=nums[0];
        long long maxi=INT_MIN;

        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i])
            {
                sum+=nums[i];
            }else{
                maxi=max(maxi,sum);
                sum=nums[i];
            }
        }
        maxi=max(maxi,sum);
       
        return maxi;
       
        
    }
};