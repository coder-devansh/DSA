class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int left=0;
        int right=0;
        long long  count=0;
        for(int i=0;i<nums.size();){
            if(nums[i]==0){
                int left=i;
                while(i<nums.size() && nums[i]==0){
                    count+=i-left+1;
                    i++;
                }
                
            }else{
                i++;
            }
        }
        return count;
        
    }
};