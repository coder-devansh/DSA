class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>result;
        for(int i=0;i<nums.size();i++){
         
            if(i>0 && nums[i]==nums[i-1])continue;
            int target=0-nums[i];
            int j=i+1;
            int k=nums.size()-1;

            while(j<k){
                long long sum=nums[j]+nums[k];
                if(sum==target){
                    
                    vector<int>ans={nums[i],nums[j],nums[k]};
                    result.push_back(ans);
                    k--;
                    j++;
                     while(j>i+1 && nums[j]==nums[j-1] && j<k)j++;
                     while(k<nums.size()-1 && nums[k]==nums[k+1] && j<k)k--;
                }
               else  if(sum>target){
                    k--;
                }else
                {
                    j++;
                }
               
            }
           
        }
        return result;
        
    }
};