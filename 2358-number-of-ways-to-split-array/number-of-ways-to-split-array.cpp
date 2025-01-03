class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long >prefix(nums.size(),0);
        vector<int>suffix(nums.size(),0);
        long long sum=0;
        int i=0;
        for(auto it:nums){
            sum+=it;
            if(i<nums.size()){
                 prefix[i]=sum;

            }
            i++;
           

        }sum=0;
        long long  total_sum=0;
        for(int j=nums.size()-1;j>=0;j--){
            total_sum+=nums[j];
            suffix[j]=sum;

        }
        sum=0;
        for(int i=0;i<nums.size();i++){
           if(i<nums.size()-1 && prefix[i]>=total_sum-prefix[i])
           {
            sum++;
           }

            
            
        }
        return sum;
        
    }
};