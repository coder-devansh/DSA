class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero=0;
        long long product=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zero++;
            }
            else{
                product*=nums[i];
            }
        }
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                if(zero)ans.push_back(0);
                else ans.push_back(product/nums[i]);
            }
            if(nums[i]==0){
                if(zero>1){
                    ans.push_back(0);
                }
                else ans.push_back(product);
            }
        }
        return ans;

        
    }
};