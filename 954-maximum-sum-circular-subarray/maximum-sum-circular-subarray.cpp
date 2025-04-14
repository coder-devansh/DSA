class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum=0;
        int max_sum=INT_MIN;
        int total_sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i%nums.size()];
            total_sum+=nums[i%nums.size()];
            if(sum>max_sum){
                max_sum=sum;
            }
            if(sum<0){
                sum=0;
            }


        }
        sum=0;
        int min_sum=INT_MAX;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i%nums.size()];
            if(sum<min_sum){
                min_sum=sum;
            }
            if(sum>0){
                sum=0;
            }
        }
        if(max_sum<0){
            return max_sum;
        }
        return max(max_sum,total_sum-min_sum);
        
        
        
    }
};