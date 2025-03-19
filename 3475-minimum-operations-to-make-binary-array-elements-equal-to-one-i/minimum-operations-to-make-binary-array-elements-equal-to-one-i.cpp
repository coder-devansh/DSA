class Solution {
public:
    int minOperations(vector<int>& nums) {
        int left=0;
        int right=0;
        int count=0;
        while(right<nums.size()){
            while(right<nums.size() && nums[right]!=0){
                right++;
            }
            if(right+3<=nums.size()){
                count++;
                int i=0;
                for(i=right;i<right+3;i++){
                    nums[i]=1-nums[i];
                }
            
               
            }
            right++;
            
        }
        for(auto it:nums){
           if(it==0) return -1;
        }

        return count;

        
    }
};